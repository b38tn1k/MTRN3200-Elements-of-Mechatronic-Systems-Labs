#ifndef _ADC_
#define _ADC_ 1

/*STANDARD LIBRARIES*/
#include <avr/io.h>
#include <avr/interrupt.h>

/*USER-DEFINED LIBRARIES*/
#include <typedefs.h>
/*PORT DECLARATIONS*/
#define ADC_PORT PORTF
#define ADC_DDR DDRF
#define ADC_PIN PINF
/*CONSTANTS AND VARIANCES*/
#define AVCC 4.89
extern volatile float adc_result;
extern volatile unsigned char Seg7_Led_Buf[4];
/*FUNCTION DECLARATIONS*/
void ADC_Init(u08);


#endif
