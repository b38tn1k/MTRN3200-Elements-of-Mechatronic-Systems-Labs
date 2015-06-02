#ifndef _KEY_
#define _KEY_
/*STANDARD LIBRARIES*/
#include <avr/io.h>
/*USER-DEFINED LIBRARIES*/
#include <typedefs.h>
/*PORT DECLARATIONS*/
#define KEY_COL0_DDR   DDRJ
#define KEY_COL0_PORT  PORTJ
#define KEY_COL0_PIN   PINJ
#define KEY_COL0_IO    0
#define KEY_PORT  PORTJ
#define KEY_DDR   DDRJ
#define KEY_INPUT PINJ
#define KEY_ROW1 7
#define KEY_ROW2 6
#define KEY_ROW3 5
#define KEY_ROW4 4
#define KEY_COL1 3
#define KEY_COL2 2
#define KEY_COL3 1 
#define KEY_COL4 0
/*FUNCTION DECLARATIONS*/
//extern void key_init(void);
extern unsigned char return_col_PIN(void);
extern unsigned char key_scan(void);
extern unsigned char read_key(void);
extern void KEY_Init(void);
//extern unsigned char KEY_read(void);
//extern unsigned char KEY_scan(void);
#endif
