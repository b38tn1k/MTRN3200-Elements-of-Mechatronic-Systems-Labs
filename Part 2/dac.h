#ifndef _DAC_
#define _DAC_ 1

/*STANDARD LIBRARIES*/
#include <avr/io.h>
//#include <avr/interrupt.h>

/*USER-DEFINED LIBRARIES*/
#include <typedefs.h>
#include <spi.h>

/*PORT Declearation*/
#define DAC_PORT PORTK
#define DAC_DDR DDRK
#define DAC_PIN 6

/*CONSTANTS*/
#define DAC_REFVCC 4.89

/*FUNCTION DECLARATIONS*/
void DAC_Init(void);
void DAC_Write(u08, u16);
u16 DAC_V2N(float);

#endif
