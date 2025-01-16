/*
 * adc.c
 *
 *  Created on: Jan 9, 2025
 *      Author: baris
 */


#include "adc.h"

#define ADC12EN		(1U<<28)
#define GPIOAEN 	(1U<<17)
#define ANALOG_MODE	(3U<<0)
#define ADEN		(1U<<1)
#define ADRDY       (1U<<0)
#define CONTCONV    (1U<<13)
#define RES12BIT	(0U<<3)
#define CYCLES		(0U<<3)
#define CONVLENGTH  (0U<<0)
#define CHANNEL1	(1U<<0)
#define ADCSTART	(1U<<2)
#define EOC			(1U<<2)
void adc_init(void){


	RCC->AHBENR	|=	ADC12EN;
	RCC->AHBENR	|=	GPIOAEN;
	GPIOA->MODER|= 	ANALOG_MODE;


	ADC1->CFGR 	|= RES12BIT;
	ADC1->SMPR1 |= CYCLES;
	ADC1->CR	|= ADEN;
	ADC1->SQR1  |= CONVLENGTH;
	ADC1->SQR1  |= CHANNEL1;

	while(!(ADC1->ISR &	ADRDY));

}

void adc_start(void){

	ADC1->CFGR 	|= CONTCONV;
	ADC1->CR	|= ADCSTART;


}

uint32_t adc_read(void){


	while(!(ADC1->ISR & EOC));


	return ADC1->DR;



}
