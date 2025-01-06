



#include "main.h"
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)


PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
	USART1_Transmit(ch);

  return ch;
}

static float32_t output[KHZ_1_10_SIG_LEN];
extern float32_t inputSignal_f32_1kHz_10kHz[KHZ_1_10_SIG_LEN];
void running_sum(float32_t*input_singal,float32_t* output_signal,uint32_t length);
int main(void){


    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();

    running_sum(inputSignal_f32_1kHz_10kHz, output, (uint32_t)KHZ_1_10_SIG_LEN);
    while(1){



    	for(int i=0;i< (uint32_t)KHZ_1_10_SIG_LEN;i++){

    		printf("%f,",inputSignal_f32_1kHz_10kHz[i]);
    		printf("%f\n\r",output[i]);


    	}

    }


}

void running_sum(float32_t*input_signal,float32_t* output_signal,uint32_t length){




	for(int i=0;i<length;i++){


		output_signal[i]=output_signal[i-1]+input_signal[i];


	}



}




