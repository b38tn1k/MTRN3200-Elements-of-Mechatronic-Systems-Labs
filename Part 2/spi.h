#include <avr/io.h>
#include <typedefs.h>

/*PORT Declearation*/
#define SPI_PORT PORTB
#define SPI_DDR DDRB
#define MISO_PIN 3
#define MOSI_PIN 2
#define SCK_PIN 1
#define SS_PIN 0

/*Function Declearation*/
void SPI_MasterInit(void);
void SPI_MasterTransmit(u08 cData);
void SPI_Modeselect(u08 spi_mode);
void SPI_SCKspeed(u08 fre_prescale);
void SPI_Init(u08 mode,u08 prescale);
