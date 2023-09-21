/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 20/09/2023
* Description: This is a file for receiving data from Master by I2C protocol.
*/
#include "stm32f10x.h" 
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stdlib.h"

#define SDA            GPIO_Pin_6
#define SCL            GPIO_Pin_7
#define PORTS          GPIOB

#define SLAVEADDRESS   0x7B
#define ACK            0
#define NACK           1
#define WRITE          0
#define READ           1

void configuration(void);
void Delay(int time);
void checkDataOfLed(void);
void waitForReceiveData(void);
uint8_t receiveDataFrame(void);
uint8_t receiveAddress(void);
void ActiveOfSlave(uint8_t* dataReceive, uint8_t sizeData);
void waitForEndFrame(void);

//void setInputForPinSDA(void);
void setOutputForPinSDA(void);

int main(void){
	
	uint8_t *dataReceive = (uint8_t*)malloc(2*sizeof(uint8_t));
	
	//dataReceive = (uint8_t*)realloc(dataReceive,5*sizeof(uint8_t));
	
	configuration();
	
  ActiveOfSlave(dataReceive, 2);
	
	checkDataOfLed();
	
	free(dataReceive);
	
	return 0;
}

void configuration(){
	
	GPIO_InitTypeDef gpio;
	
	/*ENABLE CLOCK */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	/* PB6 SDA*/     /* PB7 SCL*/
	gpio.GPIO_Pin    = SDA | SCL;
	gpio.GPIO_Mode   = GPIO_Mode_IPU;
	gpio.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_Init(PORTS, &gpio);
	
	/* PC13 LED*/ 
	gpio.GPIO_Pin    = GPIO_Pin_13;
	gpio.GPIO_Mode   = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
	
}


void Delay(int time){

		for(int i = 0; i < time; i++);
}

void checkDataOfLed(){

	GPIO_SetBits(GPIOC,GPIO_Pin_13);
	Delay(200);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	Delay(200);
	
}

void setInputForPinSDA(){
	
	// Reset Port B
	PORTS->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6 );
	// Set Input
	PORTS->CRL |= GPIO_CRL_MODE6_1;
	// Set pin SDA
	PORTS->BSRR |= SDA;
}

void setOutputForPinSDA(){
	
	// Reset Port B
	PORTS->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6 );
	// Set Output
	PORTS->CRL |= GPIO_CRL_MODE6_0;
	// Set pin SDA
	PORTS->BSRR |= SDA;

}

void waitForReceiveData(){

	while(GPIO_ReadInputDataBit(PORTS, SCL) == 0){
		
		if(GPIO_ReadInputDataBit(PORTS, SDA) == 0)
		while(GPIO_ReadInputDataBit(PORTS, SCL) == 1);
		break;
	}
	
}


uint8_t receiveAddress(){

	uint8_t addressFrame_7bit;
	
	for(uint8_t i = 0; i < 7; i++){
		
	while(GPIO_ReadInputDataBit(PORTS, SCL) == 0);
	
	if(GPIO_ReadInputDataBit(PORTS, SDA) == 1) addressFrame_7bit |= 1<<i;
		
	while(GPIO_ReadInputDataBit(PORTS, SCL) == 1);
		
	}
	
	return addressFrame_7bit;
}
uint8_t WriteOrRead(){

	return GPIO_ReadInputDataBit(PORTS, SDA);
}

uint8_t receiveDataFrame(){

	uint8_t receiveData;
	for(uint8_t i =0; i < 8; i++){
		
		while(GPIO_ReadInputDataBit(PORTS, SCL) == 0);                    // tranfer data start from: bit MSB
			
		if(GPIO_ReadInputDataBit(PORTS, SDA) == 1) receiveData |= 1 << i; // LSB.....MSB  
		
		while(GPIO_ReadInputDataBit(PORTS, SDA) == 1);                    // when use:  receiveData |= 0x80 << i      MSB....LSB
		
  }
	
	return receiveData;
}

void ActiveOfSlave(uint8_t *dataReceive, uint8_t sizeData){

	uint8_t addressFrame;
	uint8_t bitWriteOrRead;
	uint8_t i = 0;
	
	
	waitForReceiveData();
	
	addressFrame = receiveAddress();
	bitWriteOrRead = WriteOrRead();
	
	setOutputForPinSDA();
	
	if(addressFrame == SLAVEADDRESS ) GPIO_ResetBits(PORTS, SDA);
	else{
		
		GPIO_SetBits(PORTS, SDA);
		while(GPIO_ReadInputDataBit(PORTS, SCL) == 0);
		setInputForPinSDA();
		return ;
	}
	
	while(GPIO_ReadInputDataBit(PORTS, SCL) == 0);
	setInputForPinSDA();
	
	
	if(bitWriteOrRead == WRITE) {                                     // Write Data 
	
		while(i < sizeData){
		
			again:
			dataReceive[i] = receiveDataFrame();
			setOutputForPinSDA();
			if(*(dataReceive + i) != 0)  GPIO_ResetBits(PORTS, SDA);     // ACK 
			else {
				
				GPIO_SetBits(PORTS, SDA);                                 // NACK
			  goto again;
			}
			while(GPIO_ReadInputDataBit(PORTS, SCL) == 0);
			setInputForPinSDA();
		
		}
	
		i++;
}

	 waitForEndFrame();
	
}

void waitForEndFrame(){

	while(GPIO_ReadInputDataBit(PORTS, SCL) == 0);
	
	while(GPIO_ReadInputDataBit(PORTS, SDA) == 0);
}
