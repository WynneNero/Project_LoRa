/* Name: net.c
 * Author: .
 * Copyright: Arduino
 * License: GPL http://www.gnu.org/licenses/gpl-2.0.html
 * Project: eboot
 * Network and W5100 chip support
 * Version: 0.3 tftp / flashing functional on TC275
 */

/* Make sure this ends up in pspr0 */
#pragma section ".pspr0_code" ax

#include "net.h"
#include "Bootloader.h"
#include "BootLoaderDebug.h"
#include "w5100_reg.h"

/* Initialise Software SPI Port On User Defined Pin */
void SoftSPi_TFTP_SpiInit(uint8 SS_pin);

/* Software SPI RxTx */
uint8 SoftSPi_TFTP_Spi_Transfer(uint8 _send);

#define REGISTER_BLOCK_SIZE 28

uint8_t registerBuffer[REGISTER_BLOCK_SIZE] = {
  0x80,                           // MR Mode - reset device
  
  // User definable data start
  GWIP0,GWIP1,GWIP2,GWIP3,        // GWR Gateway IP Address Register
  MASK0,MASK1,MASK2,MASK3,        // SUBR Subnet Mask Register
  MAC0,MAC1,MAC2,MAC3,MAC4,MAC5,  // SHAR Source Hardware Address Register
  IP0,IP1,IP2,IP3,                // SIPR Source IP Address Register
  // User definable data end
  
  0,0,                            // Reserved locations
  0,                              // IR Interrupt Register
  0,                              // IMR Interrupt Mask Register
  0x07,0xd0,                      // RTR Retry Time-value Register
  0x80,                           // RCR Retry Count Register
  0x55,                           // RMSR Rx Memory Size Register, 2K per socket
  0x55                            // TMSR Tx Memory Size Register, 2K per socket
};

void netWriteReg(uint16_t address, uint8_t value) {

  //Send uint8_t to Eth controller

  SS_LOW();
  SoftSPi_TFTP_Spi_Transfer(SPI_WRITE);
  SoftSPi_TFTP_Spi_Transfer((uint8)(address >> 8));
  SoftSPi_TFTP_Spi_Transfer((uint8)(address & 0xFF));
  SoftSPi_TFTP_Spi_Transfer(value);
  SS_HIGH();

   //turn off SPI
}

uint8_t netReadReg(uint16_t address) {
  //Read uint8_t from Eth controller
  uint8_t returnValue;

  SS_LOW();
  SoftSPi_TFTP_Spi_Transfer(SPI_READ);
  SoftSPi_TFTP_Spi_Transfer((uint8)(address >> 8));
  SoftSPi_TFTP_Spi_Transfer((uint8)(address & 0xFF));
  returnValue = SoftSPi_TFTP_Spi_Transfer(0);
  SS_HIGH();

  return returnValue;
}

uint16_t netReadWord(uint16_t address) {
  //Read uint16_t from Eth controler
  //return (netReadReg(address++)<<8) | netReadReg(address);

  uint8 a1, a2;

  a1 = netReadReg(address++);
  a2 = netReadReg(address);

  return ((uint16)(a1 << 8) | (uint16)a2);
}

void netWriteWord(uint16_t address, uint16_t value) {
  //Write uint16_t to Eth controler
  netWriteReg(address++, value >> 8);
  netWriteReg(address, value & 0xff);
}

void netInit() {
  //Init Wiznet Chip
  // Set up SPI

  SoftSPi_TFTP_SpiInit(TFTP_SS);

  // Configure chip select
  pinMode(TFTP_SS,OUTPUT);
  digitalWrite(TFTP_SS, HIGH);

  trace("Using Default Settings\r\n");

  // Configure Wiznet chip
  uint8_t i=0;
  for (i=0; i<REGISTER_BLOCK_SIZE; i++){
	  netWriteReg(i,registerBuffer[i]);
  }
}


/* Initialise Software SPI Port */
void SoftSPi_TFTP_SpiInit(uint8 SS_pin)
{

	int i;

	digitalWrite(SS_pin, HIGH);  // Start with SS high

	pinMode(SS_pin, OUTPUT);
	pinMode(SCK_pin, OUTPUT);
	pinMode(MISO_pin, INPUT);
	pinMode(MOSI_pin, OUTPUT);

	digitalWrite(SS_pin, HIGH);
	digitalWrite(MOSI_pin, LOW);

	/* Clear out any junk in the W5100 */
	digitalWrite(SS_pin, LOW);
	for(i = 0; i < 64; i++)
	{
		digitalWrite(SCK_pin, HIGH);
		digitalWrite(SCK_pin, LOW);
	}
	digitalWrite(SS_pin, HIGH);

}



/* Software SPI RxTx */
uint8 SoftSPi_TFTP_Spi_Transfer(uint8 _send)
{
	uint8 _receive ;
	int i;

	_receive = 0;

	for(i = 0x00u; i < 0x08 ; i++)  // There are 8 bits in a byte. MSB first
	{

		if(_send & 0x80)  // Check MSB set
		{
			digitalWrite(MOSI_pin, HIGH);  // Set MOSI
		}
		else
		{
			digitalWrite(MOSI_pin, LOW); // Clear MOSI
		}

		_send <<= 1;
		digitalWrite(SCK_pin, HIGH); // SCK high

		_receive <<= 1;
		_receive |= (IfxPort_getPinState(AURduinoPins[MISO_pin].port, AURduinoPins[MISO_pin].pinIndex) & 0x01); // Capture MISO

		digitalWrite(SCK_pin, LOW); // SCK low

	}

	/* Leave MOSI low */
	digitalWrite(MOSI_pin, LOW);

  return _receive;        // Return the received data
}



#pragma section
