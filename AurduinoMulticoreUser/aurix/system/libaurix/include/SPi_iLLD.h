/*
 * SPi_iLLD.h
 *
 *  Created on: 20 Feb 2015
 *      Author: mbeach
 */

#ifndef SPI_ILLD_H_
#define SPI_ILLD_H_

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

typedef enum  {
	SPI0_CONTINUE,
	SPI0_LAST
} SPI0TransferModeType;

typedef enum  {
	SPI1_CONTINUE,
	SPI1_LAST
} SPI1TransferModeType;

typedef enum  {
	SPI2_CONTINUE,
	SPI2_LAST
} SPI2TransferModeType;

typedef enum  {
	SPIx_CONTINUE,
	SPIx_LAST
} SPIxTransferModeType;


extern uint32 Spi0_TransferRetval;


#ifdef __cplusplus

extern "C" void Spi0_Init(uint8 CS_pin, uint32 Baudrate,
		   uint8 ClockPolarity, uint8 DataDir, uint8 ShiftEdge, uint8 DataWidth);
extern "C" uint32 Spi0_Transfer(uint8 CS_pin, uint8 SpiData,  SPI0TransferModeType SpiMode);
extern "C" void Spi0_TransferBuffer(uint8 CS_pin, uint8 *SpiData,  uint8 *SpiRxData, SPI0TransferModeType SpiMode, uint32 len);

extern "C" void Spi1_Init(uint8 CS_pin, uint32 Baudrate,
		   uint8 ClockPolarity, uint8 DataDir, uint8 ShiftEdge, uint8 DataWidth);
extern "C" uint32 Spi1_Transfer(uint8 CS_pin, uint8 SpiData,  SPI1TransferModeType SpiMode);

extern "C" void Spi2_Init(uint8 CS_pin, uint32 Baudrate,
		   uint8 ClockPolarity, uint8 DataDir, uint8 ShiftEdge, uint8 DataWidth);

extern "C" uint32 Spi2_Transfer(uint8 CS_pin, uint8 SpiData,  SPI2TransferModeType SpiMode);
extern "C" void Spi2_TransferBuffer(uint8 CS_pin, uint8 *SpiData,  uint8 *SpiRxData, SPI2TransferModeType SpiMode, uint32 len);

extern "C" void SoftSPi_CS_SpiInit(uint8 SS_pin);
extern "C" uint8 SoftSPi_CS_Spi_Transfer(uint8 SS_pin, uint8 _send, SPIxTransferModeType _mode);

#else

extern void Spi0_Init(uint8 CS_pin, uint32 Baudrate,
		   uint8 ClockPolarity, uint8 DataDir, uint8 ShiftEdge, uint8 DataWidth);

extern uint32 Spi0_Transfer(uint8 CS_pin, uint8 SpiData,  SPI0TransferModeType SpiMode);
extern void Spi0_TransferBuffer(uint8 CS_pin, uint8 *SpiData,  uint8 *SpiRxData, SPI0TransferModeType SpiMode, uint32 len);

extern void Spi1_Init(uint8 CS_pin, uint32 Baudrate,
		   uint8 ClockPolarity, uint8 DataDir, uint8 ShiftEdge, uint8 DataWidth);

extern uint32 Spi1_Transfer(uint8 CS_pin, uint8 SpiData,  SPI1TransferModeType SpiMode);

extern uint32 Spi2_Transfer(uint8 CS_pin, uint8 SpiData,  SPI2TransferModeType SpiMode);
extern void Spi2_TransferBuffer(uint8 CS_pin, uint8 *SpiData,  uint8 *SpiRxData, SPI2TransferModeType SpiMode, uint32 len);


#endif


#ifdef __cplusplus
} // extern "C"
#endif


#endif /* SPI_ILLD_H_ */
