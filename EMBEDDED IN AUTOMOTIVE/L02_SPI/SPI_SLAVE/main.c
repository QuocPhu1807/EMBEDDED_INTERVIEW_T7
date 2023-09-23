/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 16/09/2023
* Description: This file is used for receiving data from Master. 
*/

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stdlib.h"
#include "Delay.h"

#define SCLK    GPIO_Pin_13
#define MOSI    GPIO_Pin_15
#define SS      GPIO_Pin_12
#define PORTS   GPIOB

#define LED     GPIO_Pin_13

void configuration(){

	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin   = SCLK | MOSI ;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPD;
	GPIO_Init(PORTS, &gpio);
	
	gpio.GPIO_Pin   = SS;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(PORTS, &gpio);
	
	gpio.GPIO_Pin   = LED;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOC,&gpio);
	
}

uint8_t receiveData(){
	
	uint8_t dataReceive;
	
	while(GPIO_ReadInputDataBit(PORTS, SS) == 1);
	
	for(uint8_t i = 0; i < 8 ; i++){
	
	while(GPIO_ReadInputDataBit(PORTS, SCLK) == 0);   // CPHA = 0 : leading edge is rising edge which is sampled data
	
	if(GPIO_ReadInputDataBit(PORTS, MOSI) == 1)  dataReceive |= 1 << i;
		
	while(GPIO_ReadInputDataBit(PORTS, SCLK) == 1);
		
	}
	
	return dataReceive;
}

void ledCode(){

		GPIO_SetBits(GPIOC,LED);
		delayMs(100);
		GPIO_ResetBits(GPIOC,LED);
		delayMs(100);
}


int main(){

		configuration();
	
	  uint8_t *receivedata = (uint8_t*)malloc(4*sizeof(uint8_t));
	
		uint8_t i = 0;
		
		while(i < 4){
		
			*receivedata = receiveData();                   
		
			ledCode();                     // receive data: 1 byte after turning on the led PC13
			receivedata++;
			i++;
			
		}	
	  return 0;
}
