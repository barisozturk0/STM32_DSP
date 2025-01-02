/*
 * usart.h
 *
 *  Created on: Nov 21, 2024
 *      Author: VICTUS
 */



#include "main.h"

#define   USART1EN (1U<<14)
#define   GPIOCEN  (1U<<19)
#define   AF7      (0x07)
#define   TXE      (1U<<7)

void USART_Init(void);
uint16_t baudrate_calc(uint32_t fclk, uint32_t baudrate);
void baudrate_set(uint32_t fclk, uint32_t baudrate);
void USART1_Transmit(int c);


