#ifndef _MAIN_
#define _MAIN_ 1
/*STANDARD LIBRARIES*/
#include <avr/io.h>
#include <avr/interrupt.h>
/*USER-DEFINED LIBRARIES*/
#include <typedefs.h>
#include <timing.h>
#include <ledarray.h>

/*CONSTANTS AND VARIABLES*/
#define PRESCALER1 0x01
#define PRESCALER3 0x04
//variables
volatile u08 LEDARRAY_FLAG = 0;
volatile u08 time_step = 0;
volatile u08 time_step112 = 0;
/*FUNCTION DECLARATIONS*/
void init_mtrn3200(void);
#endif


