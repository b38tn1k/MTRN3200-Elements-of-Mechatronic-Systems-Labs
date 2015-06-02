#ifndef _MAIN_
#define _MAIN_ 1


/*STANDARD LIBRARIES*/
#include <avr/io.h>
#include <avr/interrupt.h>


/*USER-DEFINED LIBRARIES*/
#include <typedefs.h>
#include <timing.h>
#include <7segmentled.h>
#include <adc.h>
#include <dac.h>
#include <pwm.h>

/*PORT DECLARATIONS*/
#define DEBUG_PORT PORTH
#define DEBUG_DDR DDRH
#define DEBUG_PIN0 3
#define DEBUG_PIN1 4

/*CONSTANTS AND VARIABLES*/
#define PRESCALER0 0x05
#define PRESCALER1 0x04
#define ADC_CHANNEL 0x02
#define DAC_CHANNEL0 0
#define DAC_CHANNEL1 1

volatile float desired_volt;
volatile float adc_result;
volatile u16 desired_volt_indx;
volatile u08 time_step;
volatile u08 desired_pulse_width;


volatile u08 INC_FLAG = 0;


/*FUNCTION DECLARATIONS*/
void init_mtrn3200(void);


#endif
