



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

fir_filter fir;
uint32_t curr_val;
uint32_t output_signal;
int main(void){


	System_Clock_Config();
	SysTick_Handler();

    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();

    adc_init();
    adc_start();
    fir.Cutoff_Freq=10000;
    fir.Sampling_Freq=25000;
    fir.Windows=Hamming;
    init_filter(&fir);


    while(1){

    	curr_val=adc_read();
    	output_signal=start_filter(&fir,(float32_t) curr_val);

    	printf("%d,",(int)curr_val);
    	printf("%d\n\r",(int)output_signal);





    }






}



