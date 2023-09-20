#include  "stm32f10x.h"

void delay(int time){

for(int i = 0 ; i< time; i++);
	
}
int main(void){
	
	// set xung clock cho PORT C
	RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN ;
	
	// Reset port C
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	
	//Set Port C
	
	while(1){
		
	GPIOC->BSRR = GPIO_BSRR_BR13;
	delay(100000);
		
	GPIOC->BSRR = GPIO_BSRR_BS13;
	delay(100000);
		
	}
	
	return 0;
	
	
}