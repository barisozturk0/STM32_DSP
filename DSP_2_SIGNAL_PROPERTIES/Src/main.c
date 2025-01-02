



#include "main.h"

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
	USART1_Transmit(ch);

  return ch;
}

float32_t sig_mean;
float32_t sig_variance;
float32_t sig_std;
float32_t sig_std_dsp;
extern float32_t inputSignal_f32_1kHz_15kHz[KHZ_1_15_SIG_LEN];

static float32_t signal_mean(float32_t *signal_value,uint32_t signal_len);
static float32_t signal_variance(float32_t *signal_value,uint32_t signal_len,float32_t mean);
static float32_t signal_std(float32_t variance);
int main(void){


    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();

    sig_mean=signal_mean((float32_t*)inputSignal_f32_1kHz_15kHz,(uint32_t)KHZ_1_15_SIG_LEN);
    sig_variance=signal_variance((float32_t*)inputSignal_f32_1kHz_15kHz,(uint32_t)KHZ_1_15_SIG_LEN,(float32_t)sig_mean);
    sig_std=signal_std((float32_t)sig_variance);
    arm_std_f32((float32_t*)inputSignal_f32_1kHz_15kHz, (uint32_t)KHZ_1_15_SIG_LEN, &sig_std_dsp);


	while(1){

		printf("sig_mean=%f \n\r",sig_mean);
		printf("sig_var=%f \n\r",sig_variance);
		printf("sig_std=%f \n\r",sig_std);


			for(int j=0;j<10000;j++);



	}



}


static float32_t signal_mean(float32_t *signal_value,uint32_t signal_len){

	float32_t mean=0.0;

	for(int i=0;i<signal_len;i++){

		mean=mean+signal_value[i];

	}

	mean = mean/((float32_t)signal_len);

	return mean;




}
static float32_t signal_variance(float32_t *signal_value,uint32_t signal_len,float32_t mean){

	float32_t variance=0.0;

	for(int i=0;i<signal_len;i++){

		variance=variance+powf((signal_value[i]-mean),2);

	}
	variance=variance/((float32_t)signal_len-1);
	return variance;



}

static float32_t signal_std(float32_t variance){


	return sqrtf(variance);

}

