#ifndef NET_H
#define NET_H

/*** Bit Bashed SPI for TFTP Download ***/

/* Pin definitions for ICP SPI port	*/
#define SCK_pin 	62
#define MISO_pin 	61
#define MOSI_pin 	63
#define TFTP_SS  	10

/* Pin definitions for P406 SPI port with default slave select */
/*#define SCK_pin 	52
#define MISO_pin 	50
#define MOSI_pin 	51
#define TFTP_SS  	10*/

/* Pin definitions for P406 SPI port with pin53 slave select (MDUINO-21) */
/*#define SCK_pin 	52
#define MISO_pin 	50
#define MOSI_pin 	51
#define TFTP_SS  	53*/

/* User Defined Network Settings */

/* Gateway Address */
#define GWIP0 	192
#define GWIP1	168
#define GWIP2	3
#define GWIP3	1

/* Subnet Mask */
#define MASK0	255
#define MASK1	255
#define MASK2	255
#define MASK3	0

/* MAC Address */
#define MAC0	0x12
#define MAC1	0x34
#define MAC2	0x45
#define MAC3	0x78
#define MAC4	0x9A
#define MAC5	0xBC

/* IP Address */
#define IP0		192
#define IP1		168
#define IP2		3
#define IP3		177


/* DO NOT EDIT BELOW THIS LINE */

void netWriteReg(uint16_t address, uint8_t value);
uint8_t netReadReg(uint16_t address);
uint16_t netReadWord(uint16_t address);
void netWriteWord(uint16_t address, uint16_t value);

void netInit();

#define SS_LOW() digitalWrite(TFTP_SS, LOW)
#define SS_HIGH() digitalWrite(TFTP_SS, HIGH)

#define SPI_WRITE (0xF0)
#define SPI_READ (0x0F)

#endif /* NET_H */
