/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 16/09/2023
* Description: This file is used for transmiting data from Master. 
*/

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

#define SCLK    GPIO_Pin_13
#define MOSI    GPIO_Pin_15
#define SS      GPIO_Pin_12
#define PORTS   GPIOB

#define LED     GPIO_Pin_13

void delay(int time){

	for(int i = 0; i < time; i++);
	
}

void configuration(){

	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	gpio.GPIO_Pin = SCLK | MOSI | SS;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(PORTS, &gpio);
	
	gpio.GPIO_Pin   = LED;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC,&gpio);
}

void spiInit(){
	
	GPIO_SetBits(PORTS, SS);        
	GPIO_ResetBits(PORTS, SCLK);     // Set CPOL : 0   // idle state
	GPIO_ResetBits(PORTS, MOSI);
	
}

void clockPulse(){                
	
	GPIO_SetBits(PORTS, SS);        // CPHA = 0 : leading edge is rising edge which is sampled data
	delay(100);
	GPIO_ResetBits(PORTS, SS);
	delay(100);
		
}

void transmitData(int inputData){
	
	GPIO_ResetBits(PORTS, SS);
	
	for(uint8_t i = 0; i < 8; i++){
	
			if(inputData & (1 << 0))   GPIO_SetBits(PORTS, MOSI);
			else GPIO_ResetBits(PORTS, MOSI);
		
			clockPulse();
	}
	
	GPIO_SetBits(PORTS, SS);
	delay(50);
}

void ledCode(){
		
	GPIO_ResetBits(GPIOC,LED);
	delay(100);
	GPIO_SetBits(GPIOC,LED);
	delay(100);
}

int main(){
	
	configuration();
	
	uint8_t inputData[] = {0x30, 0x40, 0x70, 0x90};
	uint8_t i = 0;
	
	spiInit();
	
	while(i < 4){
			
			transmitData(inputData[i]);
		
			ledCode();
			i++;	
	}
	
	return 0;
	}