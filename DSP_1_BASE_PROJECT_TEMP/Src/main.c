



#include "main.h"

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
	USART1_Transmit(ch);

  return ch;
}

float svariable;

extern float _5hz_signal[SIGNAL_LEN];
extern float _10hz_signal[SIGNAL_LEN];
extern float _10_50hz_signal[SIGNAL_LEN];
void plot_signal(void);


int main(void){


    SCB->CPACR|=(1U<<20);
    SCB->CPACR|=(1U<<21);
    SCB->CPACR|=(1U<<22);
    SCB->CPACR|=(1U<<23);

    USART_Init();


	while(1){





		for(int i=0;i<SIGNAL_LEN;i++){


		printf("%f \n\r",_10_50hz_signal[i]);

			for(int j=0;j<10000;j++);


	}






	}



}


void plot_signal(void){


	for(int i=0;i<SIGNAL_LEN;i++){

		svariable=_5hz_signal[i];



}
}
