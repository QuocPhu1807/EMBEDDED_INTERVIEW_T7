//#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void config(){

	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	gpio.GPIO_Pin   = GPIO_Pin_13;
	gpio.GPIO_Speed = GPIO_Speed_10MHz;
	gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOC, &gpio);
	
	
}

void delay(int time){
	
	for(uint8_t i =0 ; i< time; i++);
	
}


int main(){

	// Enable Clock port C
	//RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	// Reset port C
	
	//GPIOC->CRH &= (GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	//
	//GPIOC->CRH |= GPIO_CRH_MODE13_0;
	
	config();
	
	while(1){
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delay(100000);
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay(100000);
	
	}
}