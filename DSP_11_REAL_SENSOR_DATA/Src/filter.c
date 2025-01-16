/*
 * filter.c
 *
 *  Created on: Jan 10, 2025
 *      Author: baris
 */

#include "filter.h"




static float32_t imp_response[FILTER_LENGTH];

void init_filter(fir_filter*filter){

	float32_t sinc_out[FILTER_LENGTH];
	float32_t window_out[FILTER_LENGTH];

	filter->buffer=(float32_t *)calloc(FILTER_LENGTH,sizeof(float32_t));



	filter->out=0;
	float32_t x=0;

	int M=((FILTER_LENGTH-1)/2);
	for(int n=0;n<10;n++){

      x=(float32_t)2*filter->Cutoff_Freq*(float32_t)(n-M)/filter->Sampling_Freq;


      if(n==M){
    	  sinc_out[n]=2*(filter->Cutoff_Freq/filter->Sampling_Freq);




      }

      else{

    	  sinc_out[n]=2.0*(filter->Cutoff_Freq/filter->Sampling_Freq)*sinc(x);

      }

	}

	if(filter->Windows==Hamming){
		for(int n=0;n<FILTER_LENGTH;n++){

			window_out[n]= 0.54 - (0.46*arm_cos_f32(2*PI*n/((float32_t)FILTER_LENGTH-1)));

		}

	}
	if(filter->Windows==Hanning){
		for(int n=0;n<FILTER_LENGTH;n++){

			window_out[n]= 0.50 - (0.50*arm_cos_f32(2*PI*n/((float32_t)FILTER_LENGTH-1)));

		}
	}

	for(int n=0;n<FILTER_LENGTH;n++){

		imp_response[n]=(window_out[n])*(sinc_out[n]);

		}



}

float32_t start_filter(fir_filter*filter,float32_t current_val){


	uint32_t sumidx=0;

	filter->buffer[filter->buffidx]=current_val;
	filter->buffidx++;



	if(filter->buffidx==FILTER_LENGTH){

		filter->buffidx=0;

	}

	sumidx=filter->buffidx;
	for(int i =0; i<FILTER_LENGTH;i++){


		if(sumidx>0)
			sumidx--;
		else
			sumidx=FILTER_LENGTH-1;




		filter->out+=filter->buffer[sumidx]*imp_response[i];
	}



	return filter->out;


}

float32_t sinc(float32_t x){



	 if (x == 0.0) {
	         return 1.0;
	     } else {
	         return arm_sin_f32(PI * x)/ (PI * x);
	     }
}





