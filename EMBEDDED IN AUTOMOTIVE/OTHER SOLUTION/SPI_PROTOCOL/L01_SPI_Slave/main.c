/*
* File: main.c
* Author: Doan Quoc Phu
* Date: 16/09/2023
* Description: This file is used for transmiting data from Master by SPI protocol. 
*/

#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_tim.h"

#define LED    GPIO_Pin_13

#define SS     GPIO_Pin_12
#define MOSI   GPIO_Pin_15
#define MISO   GPIO_Pin_14
#define SCLK   GPIO_Pin_13

#define PORTS  GPIOB

void configuration(){

	GPIO_InitTypeDef gpio;
	SPI_InitTypeDef spi;
	TIM_TimeBaseInitTypeDef timBaseInit;
	
	/*ENABLE CLOCK*/
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPBEN, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPCEN, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1ENR_SPI2EN, ENABLE);
	RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	/* PB15 MOSI*/  
	/* PB13 SCLK*/  
	gpio.GPIO_Pin   = MOSI | SCLK ;
	gpio.GPIO_Mode  = GPIO_Mode_AF_PP;
	gpio.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(PORTS, &gpio);
	
	/* PB15 MOSI*/  
	gpio.GPIO_Pin   = SS ;
	gpio.GPIO_Mode  = GPIO_Mode_AF_OD;
	gpio.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(PORTS, &gpio);
	
	/* GPIOC*/
	gpio.GPIO_Pin = LED;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &gpio);
	
	/* SPI2*/
	spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
	spi.SPI_FirstBit = SPI_FirstBit_MSB;
	spi.SPI_NSS = SPI_NSS_Soft ;
	spi.SPI_CPHA = SPI_CPHA_1Edge;
	spi.SPI_CPOL = SPI_CPOL_Low;
	spi.SPI_Mode = SPI_Mode_Slave;
	spi.SPI_DataSize = SPI_DataSize_8b;
	spi.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	
	SPI_Init(SPI2, &spi);
	SPI_Cmd(SPI2, ENABLE);
	
	/* TIM2*/
	timBaseInit.TIM_Prescaler = 72 - 1;
	timBaseInit.TIM_CounterMode = TIM_CounterMode_Up ;
	timBaseInit.TIM_Period = 0xFFFF;
	
	TIM_TimeBaseInit(TIM2, &timBaseInit);
	TIM_Cmd(TIM2, ENABLE);
	
}

void Delay(int time){

	for(int i = 0; i < time; i++);
}

int main(){
	
	configuration();
	
	uint8_t dataReceive;
	
	while(1){
			
		dataReceive = SPI_I2S_ReceiveData(SPI2);
		
		GPIO_SetBits(GPIOC,LED);
		Delay(100);
		GPIO_ResetBits(GPIOC,LED);
		Delay(100);
		
	}
	

	
  return 0;
}