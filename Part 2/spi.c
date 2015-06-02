#include <spi.h>

void SPI_MasterTransmit(u08 cData)
{
//start data transmission
        SPDR = cData;

//wait for transmission complete
        while(!(SPSR & (1<<SPIF)));


//clear SPI interrupt flag
        cData = SPSR;
        cData = SPDR;


}

void SPI_MasterInit(void)

{
//confirm that ss output
        SPI_PORT |=(1<<SS_PIN);
//set MOSI, SCK and SS output

        SPI_DDR |=
                (1<<MOSI_PIN)|(1<<SCK_PIN)|(1<<SS_PIN);
//enable SPI and select master SPI mode
        SPCR |= (1<<SPE)|(1<<MSTR);
//disable SPI interrupt
        SPCR &= ~(1<<SPIE);
}

void SPI_Modeselect(u08 spi_mode)

{ //Serial Data Reading Mode: set clock polarity and
//phase.See SPCR on ATmega1280 data sheet.
        switch(spi_mode)
        {

        case 0:
                SPCR = SPCR&(~(1<<CPOL))&(~(1<<CPHA));
                break;
        case 1:
                SPCR = (SPCR&(~(1<<CPOL)))|(1<<CPHA);
                break;
        case 2:
                SPCR = (SPCR|(1<<CPOL))&(~(1<<CPHA));
                break;
        case 3:
                SPCR = SPCR|(1<<CPOL)|(1<<CPHA);
                break;
        default: //defalut: sample at leading edge and//setuup at trailing edge
                SPCR = SPCR&(~(1<<CPOL))&(~(1<<CPHA));
                break;
        }
}

void SPI_SCKspeed(u08 fre_prescale)

{

//setup SCL clock speed.

//See SPCR and SPSR registers on ATmega1280 data sheet.
        switch(fre_prescale)
        {
        case 2:
                SPCR =
                        (SPCR&(~(1<<SPR1)))&(~(1<<SPR0));
                SPSR = SPSR|(1<<SPI2X);
                break;
        case 4:
                SPCR =
                        (SPCR&(~(1<<SPR1)))&(~(1<<SPR0));
                SPSR = SPSR&(~(1<<SPI2X));
                break;

        case 8:

                SPCR = (SPCR&(~(1<<SPR1)))|(1<<SPR0);
                SPSR = SPSR|(1<<SPI2X);
                break;

        case 16:

                SPCR = (SPCR&(~(1<<SPR1)))|(1<<SPR0);
                SPSR = SPSR&(~(1<<SPI2X));
                break;

        case 32:
                SPCR = (SPCR|(1<<SPR1))&(~(1<<SPR0));
                SPSR = SPSR|(1<<SPI2X);
                break;

        case 64:
                SPCR = (SPCR|(1<<SPR1))&(~(1<<SPR0));
                SPSR = SPSR&(~(1<<SPI2X));
                break;

        case 128:
                SPCR = (SPCR|(1<<SPR1))|(1<<SPR0);
                SPSR = SPSR&(~(1<<SPI2X));
                break;


        default: //default: prescalar = 16

                SPCR = (SPCR&(~(1<<SPR1)))|(1<<SPR0);
                SPSR = SPSR&(~(1<<SPI2X));
                break;

        }
}

void SPI_Init(u08 mode,u08 prescale)
{ //variable

        unsigned char temp;

//set these pins H

        SPI_PORT |= (1<<MOSI_PIN)|(1<<MISO_PIN)|(1<<SCK_PIN);

//setup SPI

        SPI_SCKspeed(prescale);

        SPI_Modeselect(mode);

        SPI_MasterInit();

//clear SPI interrupt flag

        temp = SPSR;

        temp = SPDR;
}
