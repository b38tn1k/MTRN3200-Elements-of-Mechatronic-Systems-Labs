#ifndef _LEDARRAY_
#define _LEDARRAY_ 1
/*STANDARD LIBRARIES*/
#include <avr/io.h>
/*USER-DEFINED LIBRARIES*/
#include <typedefs.h>
/*PORT DECLARATIONS*/
#define LEDARRAY_DDR DDRH
#define LEDARRAY_PORT PORTH
/*FUNCTION DECLARATIONS*/
void LEDARRAY_Init(void);
void shift_light_to_left(void);
#endif
