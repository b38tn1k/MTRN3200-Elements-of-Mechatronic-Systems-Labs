#include <dac.h>

u16 DAC_V2N(float vout){
        u16 vout_indx = 0; //variables
        const u08 gain = 1;
//DAC voltage output range is from 0v to 5v
        if(vout>=0 && vout<=5) {

//MCP4922 is a 12 bit DAC
                vout_indx = (int) ((vout * 4096) / (DAC_REFVCC * gain));
                vout_indx &= 0x0FFF;
        }
        return vout_indx;


}

void DAC_Init(){
//Initialise SPISPI_Init(0,128);

//disable serial clock and data functions
        DAC_DDR |= (1<<DAC_PIN);
        DAC_PORT |= (1<<DAC_PIN);


}

void DAC_Write(u08 channel,u16 dacdata){
//variables
        u08 data_l, data_h;

//enable serial clock and data functions
        DAC_PORT &= (~(1<<DAC_PIN));

//select channel: channel_A = 0 and channel_B =1

        if(channel) {
//select channel_B
                dacdata |= (1<<15);
        } else{
//select channel_A
                dacdata &= (~(1<<15));

        }
//VREF Input Buffer Control bit: unbuffered
        dacdata &= (~(1<<14));
//Output Fain Selection bit: gain =1
        dacdata |= (1<<13); // 1x (VOUT = VREF * D/4096)
//Output Shutdown Control bit: active mode
        dacdata |= (1<<12);
//data transferr(from MCU to DAC)
        data_l = (u08) dacdata;
        data_h = (u08) (dacdata>>8);
        SPI_MasterTransmit(data_h);
        SPI_MasterTransmit(data_l);
//disable serial clock and data functions
        DAC_PORT |= (1<<DAC_PIN);
}
