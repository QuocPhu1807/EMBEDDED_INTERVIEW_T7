/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 18/09/2023
* Description: This is a file for transmiting data which array by UART protocol.
*/

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define Tx   		GPIO_Pin_6
#define Rx   		GPIO_Pin_7
#define PORT 		GPIOB

#define LED     GPIO_Pin_13

void delayTime(int time){
	
	for(int i = 0; i < time; i++);
}

void configurationGpioUart(){

	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPBEN, ENABLE);
	
	gpio.GPIO_Pin = Tx;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(PORT, &gpio);
	
	gpio.GPIO_Pin = Rx;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(PORT, &gpio);
	
}

void configurationGpioLed(){

	// Enable clock Port C
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	// Reset Port C
	GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13);
	// Set output PC13
	GPIOC->CRH |= GPIO_CRH_MODE13_0;
	
}

void ledInit(){
	
	GPIOC->BSRR = GPIO_BSRR_BS13;
	delayTime(200);
	GPIOC->BSRR = GPIO_BSRR_BR13;
	
}

void startCondition(){

	GPIO_ResetBits(PORT,Tx);
	delayTime(10);
	
}

uint8_t transmitData(uint8_t data){
	
	uint8_t countBit = 0;
	
	for(uint8_t i = 0 ; i< 8; i++){
		
		 if(data & (1 << 0)) {
			
				countBit ++;
				GPIO_SetBits(PORT, Tx);
			
		 } else GPIO_ResetBits(PORT, Tx);
		 
		 delayTime(5);      // bit time
	}
	
	return countBit;

}

void bitParity(uint8_t countBit){
	
	if( countBit % 2 != 0) GPIO_SetBits(PORT, Tx);
	
	else GPIO_ResetBits(PORT, Tx);
	
	delayTime(5);      // bit time

}

void endCondition(){
	
	GPIO_SetBits(PORT, Tx);
	delayTime(5);      // bit time
	GPIO_SetBits(PORT, Tx);     
	delayTime(5);			 // bit time
}

int main(){
	
	configurationGpioUart();
	configurationGpioLed();
	
	uint8_t data[] = {128, 130, 145, 160};
	uint8_t i = 0;
	uint8_t countBit = 0;
	
	GPIO_SetBits(PORT, Tx);
	delayTime(1000);
	
	while(i < 4){
	
			startCondition();
			
		  countBit = transmitData(data[i]);
			
			bitParity(countBit);
			
			endCondition();
			
		  ledInit();                  // transmit data: 1 byte then turn on Led PC13
			
		  i++;
	}
	
  return 0;
}