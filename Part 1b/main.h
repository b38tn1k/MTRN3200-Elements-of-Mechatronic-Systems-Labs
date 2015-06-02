#ifndef _MAIN_
#define _MAIN_
#include <avr/io.h>/*STANDARD LIBRARIES*/
#include <avr/interrupt.h>
#include <util/delay.h>
#include <typedefs.h>/*USER-DEFINED LIBRARIES*/
#include <key.h>
#define LEDARRAY_PORT PORTH/*PORT DECLARATIONS*/
#define LEDARRAY_DDR DDRH
#define BUZZER_PORT PORTB
#define BUZZER_DDR DDRB
#define BUZZER_PIN 4
volatile u08 KEY_FLAG = 0; /*CONSTANTS AND VARIABLES*/
volatile u08 keyvalue;
void init_mtrn3200(void); /*FUNCTION DECLARATIONS*/
#endif

