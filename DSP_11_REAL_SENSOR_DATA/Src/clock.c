/*
 * clock.c
 *
 *  Created on: Jan 9, 2025
 *      Author: baris
 */

#include "clock.h"

#define HSIOFF	(0U<<0)
#define HSEON	(1U<<16)
#define HSERDY	(1U<<17)
#define PLLON   (1U<<24)
#define PLLRDY  (1U<<25)

#define PLLMUL9		(7U<<18)	/*	PLLMUL Value = 9							*/
#define HSEPREDIV1	(0U<< 17)	/*	HSE PREDIV = 1								*/
#define PLLSRC		(1U<<16)	/*	PLL Entry Clock Source is Selected HSE		*/
#define APB2PRSC	(0U<<11)  	/*	HCLK is not divided							*/
#define APB1PRSC	(4U<<8)		/*	HCLK is divided 2							*/
#define AHBPRSC		(0U<<4)		/*	AHB Clock is not divided					*/
#define SYSCLK		(2U<<0)		/*	PLL is selected for System Clock			*/

#define FLATENCY_2	(2U<<0)		/*	Flash Latency is selected Two Wait States	*/

void System_Clock_Config(){

	RCC->CR &= HSIOFF; /*Disable HSI Clock */

	/*Configure the PLL */

	RCC->CFGR |= PLLMUL9;
	RCC->CFGR &= HSEPREDIV1;
	RCC->CFGR |= PLLSRC;
	RCC->CFGR &= APB2PRSC;
	RCC->CFGR |= APB1PRSC;
	RCC->CFGR &= AHBPRSC;
	RCC->CFGR |= SYSCLK;

	RCC->CR |= HSEON;
	while(!(RCC->CR & HSERDY));


	RCC->CR |= PLLON;
	while(!(RCC->CR & PLLRDY));

	FLASH->ACR |= FLATENCY_2;





}
