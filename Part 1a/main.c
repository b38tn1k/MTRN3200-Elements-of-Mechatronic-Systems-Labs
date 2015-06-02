#include <main.h>
int main(void){
	//microcontroller and function initialisation
	init_mtrn3200();
	//infinite loop
	while(1){
		if(LEDARRAY_FLAG){
		LEDARRAY_FLAG = 0;
		shift_light_to_left();
		}
	}
return 0;
}

void init_mtrn3200(void){
	//disable all interrupts
	cli();
	//initialise led array
	LEDARRAY_Init();
	//Interrupt and Timer Setup
	init_timer1(PRESCALER1);
	init_timer3(PRESCALER3);
	//enable all interrupts
	sei();
}

ISR(TIMER1_OVF_vect){
	//increase time step by 1 when timer/counter1
	//overflow occurs, //reset time_step
	if(++time_step>= 0x1249){
	time_step = 0;
	}
	//time_step112=0 is about 1 sec
	time_step112 = time_step % 112;
	if(time_step112 == 0){
	//set led array flag every 1 sec
	LEDARRAY_FLAG = 1;
	}
}

ISR(TIMER3_COMPA_vect){
	//set led array flag every 1 sec
	LEDARRAY_FLAG = 1;
}
