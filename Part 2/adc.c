#include <adc.h>

void ADC_Init(u08 channel){
//Reference Selection Bit: AVCC, and Channel &
//Gain Selection
ADMUX = (1<<REFS0);
ADMUX |= channel;
//ADC setup: enable ADC, ADC auto-trigger, ADC
//complete flag
ADCSRA = (1<<ADEN)|(1<<ADATE)|(1<<ADIE);
//ADC Prescaler: 64
ADCSRA |= (1<<ADPS2)|(1<<ADPS1);
//ADC Auto Trigger Source Selection:
// Timer/Counter1 Compare Match B
ADCSRB |= (1<<ADTS2)|(1<<ADTS0);

//disable the channel's corresponding I/O port
ADC_DDR &= (~(1<<channel));
ADC_PORT &= (~(1<<channel));

} 
