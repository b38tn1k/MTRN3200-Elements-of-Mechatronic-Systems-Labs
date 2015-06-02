#include <7segmentled.h>

//7-Segment LED: number and character table
//Const u08 seg7_Data[]=
const u08 Seg7_Data[]=
{0x3F,0x06,0x5B,0x4F,0x66, 
 0x6D,0x7D,0x07,0x7F,0x6F ,
 0x77,0x7C,0x39,0x5E,0x79,0x71 ,
 0x00};


//7-Segment LED: buffer
extern volatile unsigned char Seg7_Led_Buf[4];

void Seg7_Display_adc(float adc_volt){
//variables
        u08 i, temp;
        int volt;

//conversion for showing the volatge on 7 Segment
        volt = (int) (adc_volt * 100);
        Seg7_Buf[3] = volt / 1000;
        Seg7_Buf[2] = (volt % 1000) / 100;
        Seg7_Buf[1] = (volt % 100) / 10;
        Seg7_Buf[0] = volt % 10;

        for(i=0; i<4; i++) {
//conveting the number or character to be
//displayed on 7 Seg Led
                temp = Seg7_Data[Seg7_Buf[i]];
//show a decimal point
                if(i==2) {
                        temp |= 0x80;
                }
//transmit data from MCU to 74HC595
                SPI_MasterTransmit(temp);
//Seg7_send_byte(temp);

//output data and clear shift register
                Seg7_EN_PORT &= ~(1<<Seg7_EN_PIN);
                Seg7_EN_PORT |= (1<<Seg7_EN_PIN);


//turn the corresponding 7 Seg Led on and off
                Seg7_POS_PORT |= (1<<i);
                _delay_ms(1);
                Seg7_POS_PORT &= ~(1<<i);

        }
}


void Seg7_Init(void){
//7 Seg Led Position Control Init
        Seg7_POS_DDR |= ((1<<Seg7_POS0_PIN)|(1<<Seg7_POS1_PIN)|(1<<Seg7_POS2_PIN)|(1<<Seg7_POS3_PIN));

        Seg7_POS_PORT &= ~((1<<Seg7_POS0_PIN)|(1<<Seg7_POS1_PIN)|(1<<Seg7_POS2_PIN)|(1<<Seg7_POS3_PIN));

//7 Seg Led Enable Control Init (74HC595 shift register clear)
        Seg7_EN_DDR |= (1<<Seg7_EN_PIN);
        Seg7_EN_PORT |= (1<<Seg7_EN_PIN);

//IO Control

        Seg7_SET_DDR |= (1<<SHCP_PIN) | (1<<DS_PIN) |
                        (1<<MR_PIN);
        Seg7_SET_PORT |= (1<<MR_PIN);


//7 Seg Led Data Init
        Seg7_Buf[0] = 16;
        Seg7_Buf[1] = 16;
        Seg7_Buf[2] = 16;
        Seg7_Buf[3] = 16;


//SPI Control Init
        SPI_Init(0,128);


}

void Seg7_send_byte(u08 data){
        u08 i;
        for(i=128; i>0; i>>=1) {

                if(data&i) {

                        Seg7_SET_PORT |= (1<<DS_PIN);
                }
                else{


                        Seg7_SET_PORT &= ~(1<<DS_PIN);
                }
                Seg7_SET_PORT |= (1<<SHCP_PIN);
                Seg7_SET_PORT &= ~(1<<SHCP_PIN);


        }
}

