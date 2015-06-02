#include <main.h>
int main(void){
	init_mtrn3200(); //microcontroller and function initialisation
	while(1){//infinite loop
		LEDARRAY_PORT = keyvalue; //display the values on keypad
		keyvalue = read_key(); //read input from keypad
		if(keyvalue == 0x00){//if the keypad is not pressed
			BUZZER_PORT &= ~(1<<BUZZER_PIN); //turn off buzzer
		}
		else{
			BUZZER_PORT |= (1<<BUZZER_PIN); //turn on buzzer
		}
	}
	return 0;
}

void init_mtrn3200(void){
	cli(); //disable all interrupts
	LEDARRAY_DDR = 0xFF; //led array initialisation
	LEDARRAY_PORT = 0x00;
	BUZZER_DDR |= (1<<BUZZER_PIN); //buzzer initialisation
	BUZZER_PORT &= ~(1<<BUZZER_PIN);
	KEY_Init(); //keypad initialisation
	keyvalue = 0;
	sei(); //enable all interrupts
}
