#include <avr/io.h>
#include <typedefs.h>
#include <util/delay.h>
#include <spi.h>

/*PORT DECLARATIONS*/
#define Seg7_POS_PORT PORTL
#define Seg7_POS_DDR DDRL
#define Seg7_POS0_PIN 0
#define Seg7_POS1_PIN 1
#define Seg7_POS2_PIN 2
#define Seg7_POS3_PIN 3
#define Seg7_SET_PORT PORTB
#define Seg7_SET_DDR DDRB
#define SHCP_PIN 1
#define DS_PIN 2
#define MR_PIN 3
#define Seg7_EN_PORT PORTK
#define Seg7_EN_DDR DDRK
#define Seg7_EN_PIN 3

/*CONSTANTS AND VARIABLES*/
volatile unsigned char Seg7_Buf[4];

/*FUNCTION DECLARATIONS*/
extern void Seg7_Init(void);
extern void Seg7_Display_adc(float);
extern void Seg7_send_byte(u08);
