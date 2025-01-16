/*
 * filter.h
 *
 *  Created on: Jan 10, 2025
 *      Author: baris
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "stm32f303xc.h"
#include "arm_math.h"
#include <stdlib.h>
#define FILTER_LENGTH 10
float32_t sinc(float32_t x);
typedef enum{

	Hamming,
	Hanning,


}WindowType;
typedef struct{



	float32_t Cutoff_Freq;
	float32_t Sampling_Freq;
	WindowType Windows;
	float32_t *buffer;
	float32_t out;
	uint32_t buffidx;

}fir_filter;


float32_t start_filter(fir_filter*filter,float32_t current_val);
void init_filter(fir_filter*filter);
#endif /* FILTER_H_ */
