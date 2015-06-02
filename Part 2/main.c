//MAIN Program
#include <main.h>

int main(void){
//microcontroller and function initialisation
        init_mtrn3200();
//infinite loop
        while(1) {
//continuously shows the voltage measured by ADC
//on 7-Segment LED
                Seg7_Display_adc(adc_result);
                if(INC_FLAG) {
//clear incremental flag
                        INC_FLAG = 0;
//if descired voltage is not between
//0~5v, then clear the voltage
                        if(desired_volt<0 || desired_volt>5) {

                                desired_volt = 0;
                        }
//if descired pulse width is not
//between 0~255, then clear the pulse//width

                        if(desired_pulse_width<0||desired_pulse_width>255) {

                                desired_pulse_width = 0;
                        }
//convert voltage to index number
                        desired_volt_indx = DAC_V2N(desired_volt);
//output voltage by DAC
                        DAC_Write(DAC_CHANNEL0,desired_volt_indx);
                        DAC_Write(DAC_CHANNEL1,(0x0FFF-desired_volt_indx));
//output PWM
                        PWM_Write_PW(desired_pulse_width);
                }
        }
        return 0;
}

void init_mtrn3200(void){
//disable all interrupts
        cli();

//initialise debugging light

        DEBUG_DDR |= (1<<DEBUG_PIN0)|(1<<DEBUG_PIN1);
//set as ouput pins
        DEBUG_PORT &=


                (~((1<<DEBUG_PIN0)|(1<<DEBUG_PIN1))); //turn off check lights

//initialise PWM
        PWM_Init(PRESCALER0);
        desired_pulse_width = 0;

//initialise DAC
        DAC_Init();
        desired_volt = 0;

//initialise 7 Segment Led
        Seg7_Init();

//initialise ADC
        ADC_Init(ADC_CHANNEL);
        adc_result = 0;


//Interrupt and Timer Setup
        init_timer1(PRESCALER1);
        time_step = 0;


//enable all interrupts
        sei();


}

ISR(ADC_vect){

/*ADC conversion is activated and completed at
   approx every 0.5 sec*/
        u16 adc_indx = 0; //variables
        ADCSRA |= (1<<ADIF); //clear ADC interrupt flag
//read ADC conversion index (result)
        adc_indx = ADCL;
        adc_indx |= (u16) (ADCH<<8);
//convert adc index value to voltage
        adc_result = adc_indx*AVCC/1024; //2^10=1024
//ADC conversion light check
        DEBUG_PORT ^= (1<<DEBUG_PIN1);


}


ISR(TIMER1_COMPB_vect){

/*This output comparison interrupt is for ADC
   function*/
//clear timer/counter1 at every 0.5 second
        TCNT1H = 0;
        TCNT1L = 0;

//increase descired voltage by 0.5v every 5 sec

        if(++time_step>=10) {
//reset time_step
                time_step = 0;
//clear incremental flag
                INC_FLAG = 1;
//increase desired voltage
                desired_volt += 0.5;
//increase desired pulse width
                desired_pulse_width += 51;


        }
//timer/counter1 output comparsion light check
        DEBUG_PORT ^= (1<<DEBUG_PIN0);
}
