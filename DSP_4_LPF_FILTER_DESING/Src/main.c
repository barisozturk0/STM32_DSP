



#include "main.h"
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)


float* cpyarr(float32_t *dest, const float32_t *src);
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
	USART1_Transmit(ch);

  return ch;
}


extern float32_t inputSignal_f32_1kHz_10kHz[KHZ_1_10_SIG_LEN];

void impulse_response_f(float32_t Cuttoff_Freq,float32_t Sampling_Freq,uint32_t Filter_length );
void hamming_window(uint32_t Filter_length);
void filter_coeff(uint32_t Filter_length);
float32_t sinc_out[FILTER_LENGTH];
float32_t hamming_out[FILTER_LENGTH];
float32_t coeff_out[FILTER_LENGTH];
int main(void){


    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();

    impulse_response_f((float32_t)CUTOFFFREQ, (float32_t)SAMPLING, FILTER_LENGTH);
    hamming_window(FILTER_LENGTH);
    filter_coeff(FILTER_LENGTH);






    while(1){



        for(int i=0;i<FILTER_LENGTH;i++){

           	printf("%f\n\r",coeff_out[i]);

           }
    }






}
void impulse_response_f(float32_t Cuttoff_Freq,float32_t Sampling_Freq,uint32_t Filter_length ){



	float32_t x=0;
	int M=((Filter_length-1)/2);

	for(int n=0;n<Filter_length;n++){

      x=(float32_t)2*Cuttoff_Freq*(float32_t)(n-M)/Sampling_Freq;


      if(x==0)
    	  sinc_out[n]=(2*Cuttoff_Freq)/Sampling_Freq;

      else
    	  sinc_out[n]=(2*Cuttoff_Freq/Sampling_Freq)*(arm_sin_f32(x)/x);

	}

}
void hamming_window(uint32_t Filter_length){


	for(int n=0;n<Filter_length;n++){


		hamming_out[n]= 0.54 - (0.46*arm_cos_f32(2*PI*n/((float32_t)Filter_length-1)));
	}


}

void  filter_coeff(uint32_t Filter_length){


	for(int n=0;n<Filter_length;n++){

		coeff_out[n]=hamming_out[n]*sinc_out[n];

	}


}



