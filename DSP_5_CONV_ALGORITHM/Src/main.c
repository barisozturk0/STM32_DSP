



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

static float32_t output[KHZ_1_10_SIG_LEN+FILTER_LENGTH-1];
extern float32_t inputSignal_f32_1kHz_10kHz[KHZ_1_10_SIG_LEN];
static void convolution(float32_t*input_signal,float32_t*impulse_response,float32_t*output);
void impulse_response_f(float32_t Cuttoff_Freq,float32_t Sampling_Freq,uint32_t Filter_length );
void hamming_window(uint32_t Filter_length);
void filter_coeff(uint32_t Filter_length);
void signal_padded(uint32_t Filter_length,uint32_t Signal_length);
float32_t sinc_out[FILTER_LENGTH];
float32_t hamming_out[FILTER_LENGTH];
float32_t coeff_out[FILTER_LENGTH];
float32_t padded_out[FILTER_LENGTH+KHZ_1_10_SIG_LEN];
int main(void){


    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();

    impulse_response_f((float32_t)CUTOFFFREQ, (float32_t)SAMPLING, FILTER_LENGTH);
    hamming_window(FILTER_LENGTH);
    filter_coeff(FILTER_LENGTH);
    signal_padded(FILTER_LENGTH, KHZ_1_10_SIG_LEN);
    convolution(inputSignal_f32_1kHz_10kHz, coeff_out, output);





    while(1){



        for(int i=0;i<KHZ_1_10_SIG_LEN+FILTER_LENGTH-1;i++){

           	printf("%f\n\r",output[i]);

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
void signal_padded(uint32_t Filter_length,uint32_t Signal_length){



	for (int i=0;i<Signal_length+Filter_length;i++){

		 padded_out[i]=0;

	}
   for(int i=0; i<Signal_length;i++){

	   padded_out[i]=inputSignal_f32_1kHz_10kHz[i];

   }


}

 static void convolution(float32_t*input_signal,float32_t*impulse_response,float32_t*output){

	uint32_t length=KHZ_1_10_SIG_LEN+FILTER_LENGTH-1;


	for(int n=0;n<length;n++){
		output[n]=0;
		for (int i=0;i<KHZ_1_10_SIG_LEN;i++){


			if ((n - i) >= 0 && (n - i) < FILTER_LENGTH) {
				output[n]+=input_signal[i]*impulse_response[n-i];
			            }
		}

	}



}


