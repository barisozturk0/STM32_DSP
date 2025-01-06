



#include "main.h"
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

#define OFFSET1   15
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
	USART1_Transmit(ch);

  return ch;
}

static float32_t outputre[KHZ_1_10_SIG_LEN/2];
static float32_t outputim[KHZ_1_10_SIG_LEN/2];
extern float32_t inputSignal_f32_1kHz_10kHz[KHZ_1_10_SIG_LEN];
float32_t output[KHZ_1_10_SIG_LEN];
void calc_dft(float32_t* input_signal, float32_t* output_signal_re, float32_t* output_signal_im,uint32_t length);
void calc_idft(float32_t* output_signal_re, float32_t* output_signal_im,uint32_t length);

int main(void){


    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();

    calc_dft(inputSignal_f32_1kHz_10kHz, outputre, outputim, KHZ_1_10_SIG_LEN);

     calc_idft(outputre, outputim, KHZ_1_10_SIG_LEN);

   for(int i=0;i<KHZ_1_10_SIG_LEN;i++){

		printf("%f,",OFFSET1+inputSignal_f32_1kHz_10kHz[i]);
		printf("%f\n\r",output[i]);
		for(int i=0; i<9000;i++);


   }



    while(1){



    }


}

void calc_dft(float32_t* input_signal, float32_t* output_signal_re,float32_t*output_signal_im,uint32_t length){


	for(int i=0;i<length/2;i++){

		output_signal_re[i]=0;
		output_signal_im[i]=0;

	}
	for(int k=0;k<(length/2);k++){

		for(int n=0;n<length;n++){

			output_signal_re[k]=output_signal_re[k]+input_signal[n]*arm_cos_f32((2*PI*k*n)/length);
			output_signal_im[k]=output_signal_im[k]+input_signal[n]*arm_sin_f32((2*PI*k*n)/length);

		}



	}




}




void calc_idft(float32_t* output_signal_re, float32_t* output_signal_im,uint32_t length){



	for(int i=0;i<KHZ_1_10_SIG_LEN/2;i++){

		output_signal_re[i]=output_signal_re[i]/(KHZ_1_10_SIG_LEN/2);
		output_signal_im[i]=-output_signal_im[i]/(KHZ_1_10_SIG_LEN/2);

	}

	output_signal_re[0]=output_signal_re[0]/(KHZ_1_10_SIG_LEN);
	output_signal_im[0]=-output_signal_im[0]/(KHZ_1_10_SIG_LEN);
	output_signal_re[(KHZ_1_10_SIG_LEN/2)-1]=output_signal_re[(KHZ_1_10_SIG_LEN/2)-1]/(KHZ_1_10_SIG_LEN);
	output_signal_im[(KHZ_1_10_SIG_LEN/2)-1]=-output_signal_im[(KHZ_1_10_SIG_LEN/2)-1]/(KHZ_1_10_SIG_LEN);



	for(int i=0;i<length;i++){


		output[i]=0;
	}

	for(int k=0;k<length/2;k++){

		for(int n=0; n<length;n++ ){



			output[n]=output[n]+output_signal_re[k]*arm_cos_f32(2*PI*k*n/length);
			output[n]=output[n]+output_signal_im[k]*arm_sin_f32(2*PI*k*n/length);

		}

	}




}


