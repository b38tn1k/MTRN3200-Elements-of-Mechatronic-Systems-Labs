#include <ledarray.h>
void LEDARRAY_Init(void){
LEDARRAY_DDR = 0xFF; //set as output
LEDARRAY_PORT = 0x00; //trun off all the LEDs
}
void shift_light_to_left(void){
u08 MAX = 0x80;
u16 temp;
//read current output values
temp = LEDARRAY_PORT;
if(temp >= MAX || temp == 0 ){
//rest light position
LEDARRAY_PORT = 0x01;
}
else{
//shift light position to left by 1
LEDARRAY_PORT = temp << 1;
}
}
