/*
 * adc.h
 *
 *  Created on: Jan 9, 2025
 *      Author: baris
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f303xc.h"
#include "arm_math.h"

void adc_init(void);
void adc_start(void);
uint32_t adc_read(void);
#endif /* ADC_H_ */
