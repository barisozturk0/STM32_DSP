/*
 * systick.c
 *
 *  Created on: Jan 9, 2025
 *      Author: baris
 */



#include "systick.h"


#define CTRL_EN 		(1U<0)		/*	Enable SysTick				*/
#define CTRL_CLKSRC 	(1U<<2)		/*	External Clock is selected	*/



void SysTick_Handler(void){

	SysTick->CTRL =	0;

	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL  = 0;
	SysTick->CTRL |=CTRL_CLKSRC;
	SysTick->CTRL |=CTRL_EN;


}
