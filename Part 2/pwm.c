#include <pwm.h>

void PWM_Init(u08 div){
//set PWM pin as output
        PWM_DDR |= (1<<PWM_PIN);
        PWM_PORT &= (~(1<<PWM_PIN));

//use timer/counter0 as PWM source
//stop the timer/counter
        TCCR0B = 0x00;
//setup PWM width
        TCNT0 = 0x00; //clear timer/counter
        OCR0A =0x80; //set pulse length
        TCCR0A = 0x83; //set fast non-inverting PWM mode
        TIMSK0 = 0x00; //stop
//start timer/counter with a prescaler
        TCCR0B |= (0x07&div);
}

void PWM_Write_PW(u08 pulse_length){
//set pulse length
        OCR0A =pulse_length;
//clear timer/counter
        TCNT0 = 0;
}
