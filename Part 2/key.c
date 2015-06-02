#include <key.h>
void KEY_Init(void){
  //set keypad pins as input
  KEY_DDR = 0x00;
  //select input mode: the rows of keypad are Hi-Z
  //and the cols are sourcing current
  KEY_PORT = 0x0F;
}

unsigned char return_col_PIN(void){ //check the col of pressed button
//if a button is pressed, its corresponding column pin would have low input
//this check starts from right column to left column 
if((KEY_INPUT & (1<<KEY_COL4)) == 0x00){
return 0x08; }
else if((KEY_INPUT & (1<<KEY_COL3)) == 0x00){
return 0x04; }
else if((KEY_INPUT & (1<<KEY_COL2)) == 0x00){
return 0x02; }
else if((KEY_INPUT & (1<<KEY_COL1)) == 0x00){
return 0x01; } else{
}
return 0x00; }

unsigned char key_scan(void){
  //variables
  unsigned char key_value, col_pin;
  unsigned char i;
  //for each row of the keypad
  //this check starts from bottom row to top row
  for(i=0x80; i>0x08; i>>=1){
    switch(i){//checking the fourth (bottom) row by making its
   //pin output low
//if a button is pressed, its corresponding colum pin would
   //have low input
   case 0x80:
       KEY_DDR |= (1<<KEY_ROW4);
       col_pin = return_col_PIN();
       KEY_DDR &= ~(1<<KEY_ROW4);
       //when no column pins are detected as low input
       if(col_pin == 0x00){
              key_value = 0x00;}
              //a column pin is detected as low input
       else{
              key_value = (i|col_pin);
              goto loop;}
       break;

       //chekcing the third row
  case 0x40:
      KEY_DDR |= (1<<KEY_ROW3);
      col_pin = return_col_PIN();
      KEY_DDR &= ~(1<<KEY_ROW3);
      //when no column pins are detected as low input
      if(col_pin == 0x00){
             key_value = 0x00;}
             //a column pin is detected as low input
      else{
             key_value = (i|col_pin);
             goto loop;}
      break;

      //checking the second row
  case 0x20:
      KEY_DDR |= (1<<KEY_ROW2);
      col_pin = return_col_PIN();
      KEY_DDR &= ~(1<<KEY_ROW2);
      //when no column pins are detected as low input
      if(col_pin == 0x00){
             key_value = 0x00;  }
             //a column pin is detected as low input
      else{
             key_value = (i|col_pin);
goto loop; } break;
//checking the first (top )row
  case 0x10:
      KEY_DDR |= (1<<KEY_ROW1);
      col_pin = return_col_PIN();
      KEY_DDR &= ~(1<<KEY_ROW1);
      //when no column pins are detected as low input
      if(col_pin == 0x00){
             key_value = 0x00;  }
             //a column pin is detected as low input
      else{
             key_value = (i|col_pin);
goto loop; } break;
default:
      break;
    } }
loop:
    return key_value;
}

unsigned char read_key(void){
  //variables: warning static data is used
  static unsigned char key_state = 0, key_time = 0,
  key_old;
  unsigned char key_press, key_return = 0;
  //check which button is being pressed
  key_press = key_scan();
  //confirmation of the button being pressed
switch(key_state)
{
   case 0:
    //when a button is pressed in the first time
    if(key_press != 0){
    //proceed to the conformation state 1
          key_old = key_press;
          key_state = 1; }
    break;
    case 1:
//when the same button is being continuously
//pressed //for second time
if(key_press == key_old){
//proceed to the conformation state 2
    key_state = 2;
    key_time = 0;}
//new button is pressed, start all again
else{
    key_state = 0;}
break;
case 2:
//new button is pressed, start all again
if(key_press != key_old){
          key_state = 0;
    key_return = key_old;   }
//when the same button is being continously
//pressed for ten //times
else if(++key_time >= 10){
    //proceed to the conformation state 3
    key_state = 3;
    key_time = 0;
    key_return = key_old;    }
break;
case 3:
   //new button is pressed, start all again
   if(key_press != key_old){
       key_state = 0;}
   //when the same button is being continously pressed for
   //long time
else{
   //less checks are required comparing to the conformation
   //state 2
if(++key_time >= 1){ key_time = 0; key_return = key_old; }
   }
   break;
   }
   return key_return;
}
