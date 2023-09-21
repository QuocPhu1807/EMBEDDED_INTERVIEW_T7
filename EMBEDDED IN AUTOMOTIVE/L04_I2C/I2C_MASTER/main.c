/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 20/09/2023
* Description: This is a file for transfering data from Master to Slave by I2C protocol.
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

void clockForPinSCL(void);
void setInputForPinSDA(void);
void setOutputForPinSDA(void);
void setOriginalStatus(void);
void startFrame(void);
void endFrame(void);
void transmitAddressFrame(uint8_t address);
void transmitDataFrame(uint8_t inputData);

void readDataFromSlave(void);
void writeDataForSlave(void);
void dataOfMaster(uint8_t* dataReceive);


int main(void){
	
	configuration();
	
	uint8_t* dataReceive = (uint8_t *)malloc(2*sizeof(uint8_t));
	
	dataReceive[0] = 0x40;
	dataReceive[1] = 0x80;
	
	dataOfMaster(dataReceive);
	
	checkDataOfLed();
	
	return 0;
}

void configuration(){
	
	GPIO_InitTypeDef gpio;
	
	/*ENABLE CLOCK */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	/* PB6 SDA*/     /* PB7 SCL*/
	gpio.GPIO_Pin    = SDA | SCL;
	gpio.GPIO_Mode   = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_Init(PORTS, &gpio);
	
	/* PC13 LED*/ 
	gpio.GPIO_Pin    = GPIO_Pin_13;
	gpio.GPIO_Mode   = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed  = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &gpio);
	
}

void clockForPinSCL(){

	GPIO_SetBits(PORTS,SCL);
	Delay(100);
	GPIO_ResetBits(PORTS,SCL);
	Delay(100);
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

void setOriginalStatus(){

	GPIO_SetBits(PORTS, SDA);
	GPIO_SetBits(PORTS, SCL);
	
}

void startFrame(){

	GPIO_ResetBits(PORTS, SDA);
	Delay(60);
	GPIO_ResetBits(PORTS, SCL);
}

void endFrame(){
	
	GPIO_SetBits(PORTS, SCL);
	Delay(60);
	GPIO_SetBits(PORTS, SDA);
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

void transmitAddressFrame(uint8_t address){
	
	for(uint8_t i = 0 ; i < 7; i++){
		
	if( address & (1 << 0) ) GPIO_SetBits(PORTS,SDA);
		
	else GPIO_ResetBits(PORTS, SDA);	
		
	 clockForPinSCL();
	}
}

void transmitDataFrame(uint8_t inputData){
	
	for(uint8_t i = 0; i < 8; i++){
	
	if(inputData & (1<<0)) GPIO_SetBits(PORTS, SDA);
		
	else GPIO_ResetBits(PORTS, SDA);
		
	clockForPinSCL();
	}

}

void writeDataForSlave(){

	// transmit bit write to Slave
	GPIO_ResetBits(PORTS, SDA);
	clockForPinSCL();
}

void readDataFromSlave(){

	// transmit bit write to Slave
	GPIO_SetBits(PORTS, SDA);
	clockForPinSCL();
}

void dataOfMaster(uint8_t* dataReceive){
	
	uint8_t i = 0;
	again:
	
	setOriginalStatus();
	Delay(500);
	
	startFrame();
	
	transmitAddressFrame(SLAVEADDRESS);
	writeDataForSlave();
	
	// transmit data 2 byte and chech bit ACK from SLAVE.
	
	for(uint8_t i = 0; i < 2; i++){
		
	setInputForPinSDA();
	
	if(GPIO_ReadInputDataBit(PORTS, SDA) == ACK){
	
		
		setOutputForPinSDA();
		clockForPinSCL();
		transmitDataFrame(dataReceive[i]);
	}
	else if (GPIO_ReadInputDataBit(PORTS, SDA) == NACK){
		
		setOutputForPinSDA();	
		goto again;
	}
	
	i++;
}
	

		setInputForPinSDA();

	if (GPIO_ReadInputDataBit(PORTS, SDA) == NACK){
			
			setOutputForPinSDA();	
			goto again;
	}

		setOutputForPinSDA();
	  clockForPinSCL();
	  endFrame();
}
