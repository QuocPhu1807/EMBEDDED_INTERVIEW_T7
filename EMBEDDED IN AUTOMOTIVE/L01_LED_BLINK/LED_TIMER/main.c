
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "Delay.h"


int main(){

	configurationLed();
	
	while(1){
		
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delayMs(1000);
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delayMs(1000);
	
	}
}