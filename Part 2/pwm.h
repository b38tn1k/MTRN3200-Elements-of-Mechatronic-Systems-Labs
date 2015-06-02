#include <avr/io.h>
#include <typedefs.h>

/*PORT DECLARATIONS*/
#define PWM_PORT PORTB
#define PWM_DDR DDRB
#define PWM_PIN 7

/*FUNCTION DECLARATIONS*/
void PWM_Init(u08);
void PWM_Write_PW(u08);
#include <typedefs.h>/*PORT DECLARATIONS*/#define PWM_PORT PORTB#define PWM_DDR DDRB#define PWM_PIN 7/*FUNCTION DECLARATIONS*/void PWM_Init(u08);void PWM_Write_PW(u08);
