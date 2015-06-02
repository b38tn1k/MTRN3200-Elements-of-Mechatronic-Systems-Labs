#include <timing.h>

void init_timer1(u08 div){
/* 16 bit timer/counter, timer/counter1. Thetimer/counter is set to normal timer/counter modewith output comparison function.*/
//stop timer/counter
        TCCR1B = 0x00; //stop timer/counter1

//setup comparing value
        OCR1BH = 0x38;
        OCR1BL = 0x40;
//setup timer/counter
        TCCR1A = 0x00;
        TCCR1C = 0x00;
        TIMSK1 = 0x04; //output compare B interrupt enable

//start timer/counter with a prescaler
        TCCR1B |= 0x07 & div;
}
