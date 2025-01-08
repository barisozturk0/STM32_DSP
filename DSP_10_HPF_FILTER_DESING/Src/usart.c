/*
 * usart.c
 *
 *  Created on: Nov 21, 2024
 *      Author: VICTUS
 */

#ifndef USART_H_
#define USART_H_
#include "usart.h"

#include "stm32f3xx.h"


void USART_Init(void){


	//GPIOC PORT ENABLE
	RCC->AHBENR|=GPIOCEN;

	//USART1 CLOCK ENABLE
	RCC->APB2ENR|=USART1EN;

	//PC4 AF MODE SELECTED
	GPIOC->MODER&=~(1U<<8);
	GPIOC->MODER|=(1U<<9);



	//AF7 SELECTED
	GPIOC->AFR[0]|=(1<<16);
	GPIOC->AFR[0]|=(1<<17);
	GPIOC->AFR[0]|=(1<<18);
	GPIOC->AFR[0]&=~(1<<19);


	USART1->CR1&=~(1U<<0);
	//OVERSAMPLING 16 BIT
	USART1->CR1&=~(1U<<15);

	//8 BIT DATA FRAME
	USART1->CR1&=~(1U<<12);
	USART1->CR1&=~(1U<<28);

    //TRANSMIT MODE ENABLE
	USART1->CR1|=(1U<<3);

	baudrate_set(FCLK,4800);


	USART1->CR1&=~(1<<10);
	USART1->CR2&=~(1<<19);
	USART1->CR2&=~(1<<12);
	USART1->CR2&=~(1<<13);
	//USART ENABLE
	USART1->CR1|=(1U<<0);





}

void USART1_Transmit(int c) {
    while (!(USART1->ISR & TXE)); // TXE bitinin set edilmesini bekle
    USART1->TDR = c;
}


void baudrate_set(uint32_t fclk, uint32_t baudrate){

	USART1->BRR=baudrate_calc(fclk,baudrate);


}
uint16_t baudrate_calc(uint32_t fclk, uint32_t baudrate){


	return ((fclk)/baudrate);


}

#endif /* USART_H_ */

