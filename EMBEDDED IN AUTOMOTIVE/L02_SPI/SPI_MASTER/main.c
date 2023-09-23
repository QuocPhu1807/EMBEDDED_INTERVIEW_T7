/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 16/09/2023
* Description: This file is used for transmiting data from Master. 
*/

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "Delay.h"
#include "stdlib.h"

#define SCLK    GPIO_Pin_13
#define MOSI    GPIO_Pin_15
#define SS      GPIO_Pin_12
#define PORTS   GPIOB

#define LED     GPIO_Pin_13

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
	
	GPIO_SetBits(PORTS, SCLK);        // CPHA = 0 : leading edge is rising edge which is sampled data
	delayMs(100);
	GPIO_ResetBits(PORTS, SCLK);
	delayMs(100);
		
}

void transmitData(uint8_t transmitData){
	
	GPIO_ResetBits(PORTS, SS);
	
	for(uint8_t i = 0; i < 8; i++){
	
			if(transmitData & (1 << 0))   GPIO_SetBits(PORTS, MOSI);
			else GPIO_ResetBits(PORTS, MOSI);
		
			clockPulse();
	}
	
	GPIO_SetBits(PORTS, SS);
	delayMs(50);
}

void ledCode(){
		
	GPIO_ResetBits(GPIOC,LED);
	delayMs(100);
	GPIO_SetBits(GPIOC,LED);
	delayMs(100);
}

int main(){
	
	configuration();
	spiInit();
	
	uint8_t i =0;
	uint8_t *transmitdata = (uint8_t*)malloc(4*sizeof(uint8_t));
	
  transmitdata[0] = 0x40;
	transmitdata[1] = 0x50;
	transmitdata[2] = 0x60;
	transmitdata[3] = 0x70;
	
	while(i < 4){
	
		transmitData(*transmitdata);
		
		ledCode();
		
		transmitdata++;
		i++;
	}
	
  free(transmitdata);	
	return 0;
}
