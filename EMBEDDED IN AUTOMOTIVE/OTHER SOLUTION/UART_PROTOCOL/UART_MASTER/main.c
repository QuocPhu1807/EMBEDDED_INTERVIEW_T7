#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"

#define TX      GPIO_Pin_10
#define RX      GPIO_Pin_11
#define PORTS   GPIOB

#define LED     GPIO_Pin_13

void configuration(){

	GPIO_InitTypeDef gpio;
	USART_InitTypeDef uart;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
}


int main(){


}