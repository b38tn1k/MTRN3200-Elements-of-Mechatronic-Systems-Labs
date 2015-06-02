#include <timing.h>


void init_timer1(u08 div){
	/* 6 bit timer/counter, timer/counter1. The
	timer/counter is set to normal timer/counter mode
	with overflow interrupt function.*/

	//stop timer/counter
	TCCR1B = 0x00; //stop timer/counter1

	//setup timer/counter
	TCCR1A = 0x00;
	TCCR1C = 0x00;
	TIMSK1 |= 0x01; //overflow interrupt enable

	//start timer/counter with a prescaler
	TCCR1B |= 0x07 & div;
}

void init_timer3(u08 div){
/* 16 bit timer/counter, timer/counter3. The
timer/counter is set to CTC timer/counter mode with
output comparison function.*/
TCCR3B = 0x00; //stop timer/counter
OCR3AH = 0x70; //setup comparing value
OCR3AL = 0x80;
TCCR3A = 0x00; //setup timer/counter
TCCR3B = (1<<WGM32);
TCCR3C = 0x00;
TIMSK3 = 0x02; //output compare A match interrupt
//start timer/counter with a prescaler
TCCR3B |= 0x07 & div;
}
