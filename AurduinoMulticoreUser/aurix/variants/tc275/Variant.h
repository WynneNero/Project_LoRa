

/*
 * This Header File specifies any variables/defines/data etc that is
 * specific to the chip. Anything that is general to the Arduino
 * framework should be put in the respective module or in the
 * global Arduino.h header file.
 *
 *
 */

#ifndef _VARIANT_H
#define _VARIANT_H

// Definition for Marlin 3D printer driver
#define _AURIX_SHIELDBUDDY_TC275_
#define constepxr const   /* constexpr is c++11 */
#define cli()  __disable()
#define sei()  __enable()

// Simulate the C11++ static_assert
#define ASSERT_CONCAT_(a, b) a##b
#define ASSERT_CONCAT(a, b) ASSERT_CONCAT_(a, b)
#define static_assert(e,m) ;enum { ASSERT_CONCAT(assert_line_, __LINE__) = 1/(int)(!!(e)) }

#include "Arduino.h"
#include "Bootloader.h"
#include "TIMdriver.h"
#include "GeneralTimers.h"
#include "Binary.h"
#include "SbCheck.h"




#ifdef __cplusplus


#endif

#ifdef __cplusplus
extern "C"{
#endif



#undef HIGH
#undef LOW
#include "system_tc2x.h"
#include "Port/Io/IfxPort_Io.h"
#include "Std/IfxScuWdt.h"
#include "IfxStm_reg.h"

#if defined(__DCC__)
#include "IfxCpu_IntrinsicsDcc.h"

#elif defined(__GNUC__)
#include "IfxCpu_IntrinsicsGnuc.h"

#elif defined(__TASKING__)
#include "IfxCpu_IntrinsicsTasking.h"
#endif

#include <Asclin/Asc/IfxAsclin_Asc.h>
#include "Interrupts.h"
#include "Vadc.h"
#include "Ifx_CircularBuffer.h"
#include "IfxGtm_reg.h"
#include "timetick.h"
#include "Test_Time.h"
#include "analogOut.h"
#include "IfxScuCcu.h"
#include "IfxStm.h"

/* Multicore location macros */
#include "IfxMemMap.h"

/* Make iLLD GTM functions available */
#include <GTM/Tom/PwmHL/IfxGtm_Tom_PwmHL.h>
#include <GTM/Tom/Timer/IfxGtm_Tom_Timer.h>
#include <GTM/ATom/PwmHL/IfxGtm_ATom_PwmHL.h>
#include <GTM/ATom/Timer/IfxGtm_ATom_Timer.h>
#include <GTM/Trig/IfxGtm_Trig.h>
#include <GTM/std/IfxGtm_Atom.h>
#include <GTM/std/IfxGtm_CMU.h>
#include <GTM/std/IfxGtm_Tbu.h>
#include <GTM/std/IfxGtm_Tom.h>
#include <GTM/std/IfxGtm.h>

#include <Ccu6/PwmBc/IfxCcu6_PwmBc.h>

#include <IfxGpt12_reg.h>

/* Make iLLD MultiCAN functions available */
#include <Multican/Can/IfxMultiCan_can.h>
#include <Multican/Std/IfxMultiCan.h>

/* Make iLLD VADC functions available */
#include <Vadc/Adc/IfxVadc_Adc.h>
#include <Vadc/Std/IfxVadc.h>

/* Make iLLD VADC functions available */
#include <Dsadc/Dsadc/IfxDsadc_Dsadc.h>
#include <Dsadc/Std/IfxDsadc.h>

#include <IfxSrc_reg.h>

#include "Multican.h"

#if defined(__GNUC__)
#include "cint.h"
#endif

#include "tc275_pom.h"

#include <Scu/Std/IfxScuEru.h>
#include <_PinMap/IfxScu_PinMap.h>
#include "PinInterruptInit.h"

/* For WString.cpp */
#include "stdlib.h"
#include "itoa.h"
#include "dtostrf.h"


#include "EEPROM_TC275.h"

#include  "TriLib.h"

#include "vt100.h"

#include "stdio.h"
#include "stdarg.h"



/* For compatibility with older shield libraries */
#define ARDUINO 10600

#define _BV(a) (1<<a)

/* EEPROM */
#define E2START 0xAF000000ul
#define E2END  (0xAF060000ul-1ul)/* EEPROM (DFLASH) is available, last cell address */

/* TC275 clock */
#define F_CPU  200000000ul

#define HIGH 1
#define LOW 0

#define NoOfAURduinoVirtualPins		3U	// Used for additional SPI chip selects
#define ICP_P201_Pins				3U	// P201 SPI connector
#define NoOfAURduinoPins			58U + NoOfAURduinoVirtualPins + ICP_P201_Pins
#define NoOfAlternateAURduinoPins	4U

extern IfxPort_Pin const AURduinoPins[NoOfAURduinoPins];
extern IfxPort_Pin const AURduinoPinsAlternate[NoOfAlternateAURduinoPins];

void __libc_init_array(void);
void init( void );
void Reset_TC275(void);

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           12 // (79u)
#define NUM_DIGITAL_PINS     (56u)
#define NUM_ANALOG_INPUTS    (12u)

// These need adapting to Aurix
#define digitalPinToPort(P)        ((uint32)AURduinoPins[P].port)  		// ( g_APinDescription[P].pPort )
#define digitalPinToBitMask(P)     (1 << ((uint32_t)AURduinoPins[P].pinIndex))
#define digitalPinToBitMaskIOCR(P) (uint32_t)(8*(0x03u & (uint32_t)AURduinoPins[P].pinIndex))  	// ( g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   (uint32*)&((Ifx_P*)port)->OUT.U;     // (Ifx_P_OUT*)&((Ifx_P*)port)->OUT.U//( &(port->PIO_ODSR) )   MODULE_P33.OUT.U = 1; Ifx_P
#define portInputRegister(port)    (uint32*)&((Ifx_P*)port)->IN.U;     // (Ifx_P_IN*)&((Ifx_P*)port)->IN.U //( &(port->PIO_PDSR) )
/* Return the address of the IOCRx required for this pin */
IFX_INLINE uint32 *portModeRegister(Ifx_P *port, uint32 _Pin)
{
	volatile Ifx_P_IOCR0 *iocr      = &(port->IOCR0);
	uint8                 iocrIndex = ((uint32_t)AURduinoPins[_Pin].pinIndex / 4);

	return((uint32 *)&iocr[iocrIndex].U);
}


#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

// Interrupts
#define digitalPinToInterrupt(p)  ((p) < NUM_DIGITAL_PINS ? (p) : -1)

// LEDs
#define PIN_LED_13           (13u)
#define PIN_LED_RXL          (72u)
#define PIN_LED_TXL          (73u)
#define PIN_LED              PIN_LED_13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL
#define LED_BUILTIN          13

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define SPI_INTERFACE        SPI0
#define SPI_INTERFACE_ID     ID_SPI0
#define SPI_CHANNELS_NUM 4
#define PIN_SPI_SS0          (77u)
#define PIN_SPI_SS1          (87u)
#define PIN_SPI_SS2          (86u)
#define PIN_SPI_SS3          (78u)
#define PIN_SPI_MOSI         (75u)
#define PIN_SPI_MISO         (74u)
#define PIN_SPI_SCK          (76u)
#define BOARD_SPI_SS0        (10u)   /* Pin10 is default CS on SPI Ch0: MISO = P201.1, MOSI = P201.4 SCK = P201.3           */
#define BOARD_SPI_SS0_S1	 (58) //(210u)  /* Really pin 10 but this means use it with SPI Ch 1: MISO = p12, MOSI = p11 SCK = p13 */
#define BOARD_SOFT_SPI_SS0	 (59) //(211u)  /* Bit bashed SPI only p10 chip select. MISO = p50, MOSI = p51 SCK = p52   */
#define BOARD_SOFT_SPI_SS2	 (60)  //(153u)  /* Bit bashed SPI only p53 chip select. MISO = p50, MOSI = p51 SCK = p52   */
#define BOARD_SPI_SS1        (4u)	 /* Used for SD Cards on SPI Ch0: MISO = P201.1, MOSI = P201.4 SCK = P201.3 */
#define BOARD_SPI_SS2        (53u)   /* Not used yet */
#define BOARD_SPI_SS3        PIN_SPI_SS3
#define BOARD_SPI_DEFAULT_SS BOARD_SPI_SS0 // BOARD_SPI_SS3


#define BOARD_PIN_TO_SPI_PIN(x) \
	(x==BOARD_SPI_SS0 ? PIN_SPI_SS0 : \
	(x==BOARD_SPI_SS1 ? PIN_SPI_SS1 : \
	(x==BOARD_SPI_SS2 ? PIN_SPI_SS2 : PIN_SPI_SS3 )))
#define BOARD_PIN_TO_SPI_CHANNEL(x) \
	(x==BOARD_SPI_SS0 ? 0 : \
	(x==BOARD_SPI_SS1 ? 1 : \
	(x==BOARD_SPI_SS2 ? 2 : 3)))

static const uint8_t SS   = BOARD_SPI_SS0;
static const uint8_t SS1  = BOARD_SPI_SS1;
static const uint8_t SS2  = BOARD_SPI_SS2;
static const uint8_t SS3  = BOARD_SPI_SS3;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;



/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)
#define WIRE_INTERFACE       TWI1
#define WIRE_INTERFACE_ID    ID_TWI1
#define WIRE_ISR_HANDLER     TWI1_Handler
#define WIRE_ISR_ID          TWI1_IRQn

#define PIN_WIRE1_SDA        (54u)
#define PIN_WIRE1_SCL        (55u)
#define WIRE1_INTERFACE      TWI0
#define WIRE1_INTERFACE_ID   ID_TWI0
#define WIRE1_ISR_HANDLER    TWI0_Handler
#define WIRE1_ISR_ID         TWI0_IRQn

/*
 * UART/USART Interfaces
 */
// Serial
#define PINS_UART            (81u)
// Serial1
#define PINS_USART0          (82u)
// Serial2
#define PINS_USART1          (83u)
// Serial3
#define PINS_USART3          (84u)

/* baud rate values at 100 MHz */
#define BAUD_9600				(48 * 1)
#define BAUD_19200				(48 * 2)
#define BAUD_38400				(48 * 4)
#define BAUD_57600				(48 * 6)
#define BAUD_115200				(48 * 12)

/* Aurix ASC definitions */
#define HTX_ASCLIN_FREQUENCY					((uint32) 100000000u)
#define HTX_ASCLIN_PRESCALER_HIGH_SPEED		    (1u)
#define HTX_ASCLIN_OVERSAMPLE_HIGH_SPEED		(4u)
#define HTX_ASCLIN_DENOMINATOR_HIGH_SPEED		(2000u)
#define HTX_ASCLIN_DIVISOR_HIGH_SPEED			(HTX_ASCLIN_FREQUENCY / ( (HTX_ASCLIN_PRESCALER_HIGH_SPEED + 1u) * (HTX_ASCLIN_OVERSAMPLE_HIGH_SPEED + 1u) ) )
#define HTX_ASCLIN_SAMPLE_POINT_HIGH_SPEED		(3u)		/* Sample-point = 1,2,3 */

#define HTX_ASCLIN_PRESCALER_LOW_SPEED			(9u)
#define HTX_ASCLIN_OVERSAMPLE_LOW_SPEED		    (15u)
#define HTX_ASCLIN_DENOMINATOR_LOW_SPEED		(3125u)
#define HTX_ASCLIN_DIVISOR_LOW_SPEED			(HTX_ASCLIN_FREQUENCY / ( (HTX_ASCLIN_PRESCALER_LOW_SPEED + 1u) * (HTX_ASCLIN_OVERSAMPLE_LOW_SPEED + 1u) ) )
#define HTX_ASCLIN_SAMPLE_POINT_LOW_SPEED		(9u)		/* Sample-point = 7,8,9 */

/* Defines for iLLD v1.0.0.11.0 */
#define IfxMultican_Status_noError IfxMultican_Status_newData

/*
 * USB Interfaces
 */
#define PINS_USB             (85u)

/*
 * Analog pins
 */
static const uint8_t A0  = 0;
static const uint8_t A1  = 1;
static const uint8_t A2  = 2;
static const uint8_t A3  = 3;
static const uint8_t A4  = 4;
static const uint8_t A5  = 5;
static const uint8_t A6  = 6;
static const uint8_t A7  = 7;
static const uint8_t A8  = 8;
static const uint8_t A9  = 9;
static const uint8_t A10 = 10;
static const uint8_t A11 = 11;
static const uint8_t DAC0 = 100;
static const uint8_t DAC1 = 101;
static const uint8_t DAC0_RF = 102;
static const uint8_t DAC1_RF = 103;
static const uint8_t CANRX = 68;
static const uint8_t CANTX = 69;
static const uint8_t SDA = 20;
static const uint8_t SCL = 21;
static const uint8_t SDA1 = 54;
static const uint8_t SCL1 = 55;
static const uint8_t SDA2 = 56;
static const uint8_t SCL2 = 57;

/* 54             |  PA16  | "A0"
*  55             |  PA24  | "A1"
*  56             |  PA23  | "A2"
*  57             |  PA22  | "A3"
*  58       TIOB2 |  PA6   | "A4"
*  69             |  PA4   | "A5"
*  60       TIOB1 |  PA3   | "A6"
*  61       TIOA1 |  PA2   | "A7"
*  62             |  PB17  | "A8"
*  63             |  PB18  | "A9"
*  64             |  PB19  | "A10"
*  65             |  PB20  | "A11"
*  66             |  PB15  | "DAC0"
*  67             |  PB16  | "DAC1"
*  68             |  PA1   | "CANRX"
*  69             |  PA0   | "CANTX"
*  70             |  PA17  | "SDA1"
*  71             |  PA18  | "SCL1"
*/
#define ADC_RESOLUTION		12

/*
 * Complementary CAN pins
 */
static const uint8_t CAN1RX = 88;
static const uint8_t CAN1TX = 89;

// CAN0
#define PINS_CAN0            (90u)
// CAN1
#define PINS_CAN1            (91u)

/* Fast IO pin definitions */
#define D0_OUT P15_OUT.B.P3
#define D1_OUT P15_OUT.B.P2
#define D2_OUT P02_OUT.B.P0
#define D3_OUT P02_OUT.B.P1
#define D4_OUT P10_OUT.B.P4
#define D5_OUT P02_OUT.B.P3
#define D6_OUT P02_OUT.B.P4
#define D7_OUT P02_OUT.B.P5
#define D8_OUT P02_OUT.B.P6
#define D9_OUT P02_OUT.B.P7
#define D10_OUT P10_OUT.B.P5
#define D11_OUT P10_OUT.B.P3
#define D12_OUT P10_OUT.B.P1
#define D13_OUT P10_OUT.B.P2
#define D14_OUT P15_OUT.B.P0
#define D15_OUT P15_OUT.B.P1

#define D16_OUT P33_OUT.B.P9
#define D17_OUT P33_OUT.B.P8
#define D18_OUT P20_OUT.B.P0
#define D19_OUT P20_OUT.B.P3
#define D20_OUT P20_OUT.B.P4
#define D21_OUT P20_OUT.B.P5
#define D22_OUT P14_OUT.B.P0
#define D23_OUT P14_OUT.B.P1
#define D24_OUT P15_OUT.B.P6

#define D25_OUT P00_OUT.B.P0
#define D26_OUT P00_OUT.B.P8
#define D27_OUT P00_OUT.B.P1
#define D28_OUT P00_OUT.B.P9
#define D29_OUT P00_OUT.B.P2
#define D30_OUT P00_OUT.B.P10
#define D31_OUT P00_OUT.B.P3
#define D32_OUT P00_OUT.B.P11
#define D33_OUT P00_OUT.B.P4
#define D34_OUT P00_OUT.B.P12
#define D35_OUT P00_OUT.B.P5
#define D36_OUT P33_OUT.B.P2
#define D37_OUT P00_OUT.B.P6
#define D38_OUT P33_OUT.B.P1
#define D39_OUT P00_OUT.B.P7

#define D40_OUT P33_OUT.B.P0
#define D41_OUT P11_OUT.B.P9
#define D42_OUT P11_OUT.B.P10
#define D43_OUT P11_OUT.B.P11
#define D44_OUT P33_OUT.B.P3

#define D45_OUT P11_OUT.B.P2
#define D46_OUT P11_OUT.B.P3
#define D47_OUT P11_OUT.B.P6
#define D48_OUT P21_OUT.B.P3
#define D49_OUT P21_OUT.B.P0

#define D50A_OUT P21_OUT.B.P2
#define D51A_OUT P13_OUT.B.P3
#define D52A_OUT P15_OUT.B.P8
#define D53A_OUT P20_OUT.B.P10

#define D50B_OUT P33_OUT.B.P4
#define D51B_OUT P02_OUT.B.P8
#define D52B_OUT P33_OUT.B.P5
#define D53B_OUT P11_OUT.B.P12

#define D54_OUT P13_OUT.B.P2
#define D55_OUT P13_OUT.B.P1

/* Analog pins with digital option */
#define A4A_OUT P10_OUT.B.P8
#define A5A_OUT P10_OUT.B.P7

#define A12A_OUT P20_OUT.B.P9
#define A12B_OUT P33_OUT.B.P10
#define A13A_OUT P33_OUT.B.P11
#define A14A_OUT P20_OUT.B.P7
#define A15A_OUT P20_OUT.B.P8


#define D0_IN P15_IN.B.P3
#define D1_IN P15_IN.B.P2
#define D2_IN P02_IN.B.P0
#define D3_IN P02_IN.B.P1
#define D4_IN P10_IN.B.P4
#define D5_IN P02_IN.B.P3
#define D6_IN P02_IN.B.P4
#define D7_IN P02_IN.B.P5
#define D8_IN P02_IN.B.P6
#define D9_IN P02_IN.B.P7
#define D10_IN P10_IN.B.P5
#define D11_IN P10_IN.B.P3
#define D12_IN P10_IN.B.P1
#define D13_IN P10_IN.B.P2
#define D14_IN P15_IN.B.P0
#define D15_IN P15_IN.B.P1

#define D16_IN P33_IN.B.P9
#define D17_IN P33_IN.B.P8
#define D18_IN P20_IN.B.P0
#define D19_IN P20_IN.B.P3
#define D20_IN P20_IN.B.P4
#define D21_IN P20_IN.B.P5
#define D22_IN P14_IN.B.P0
#define D23_IN P14_IN.B.P1
#define D24_IN P15_IN.B.P6

#define D25_IN P00_IN.B.P0
#define D26_IN P00_IN.B.P8
#define D27_IN P00_IN.B.P1
#define D28_IN P00_IN.B.P9
#define D29_IN P00_IN.B.P2
#define D30_IN P00_IN.B.P10
#define D31_IN P00_IN.B.P3
#define D32_IN P00_IN.B.P11
#define D33_IN P00_IN.B.P4
#define D34_IN P00_IN.B.P12
#define D35_IN P00_IN.B.P5
#define D36_IN P33_IN.B.P2
#define D37_IN P00_IN.B.P6
#define D38_IN P33_IN.B.P1
#define D39_IN P00_IN.B.P7

#define D40_IN P33_IN.B.P0
#define D41_IN P11_IN.B.P9
#define D42_IN P11_IN.B.P10
#define D43_IN P11_IN.B.P11
#define D44_IN P33_IN.B.P3

#define D45_IN P11_IN.B.P2
#define D46_IN P11_IN.B.P3
#define D47_IN P11_IN.B.P6
#define D48_IN P21_IN.B.P3
#define D49_IN P21_IN.B.P0

#define D50A_IN P21_IN.B.P2
#define D51A_IN P13_IN.B.P3
#define D52A_IN P15_IN.B.P8
#define D53A_IN P20_IN.B.P10

#define D50_IN P21_IN.B.P2
#define D51_IN P13_IN.B.P3
#define D52_IN P15_IN.B.P8
#define D53_IN P20_IN.B.P10

#define D50B_IN P33_IN.B.P4
#define D51B_IN P02_IN.B.P8
#define D52B_IN P33_IN.B.P5
#define D53B_IN P11_IN.B.P12

#define D54_IN P13_IN.B.P2
#define D55_IN P13_IN.B.P1


/* Analog pins with digital option */
#define A4A_IN P10_IN.B.P8
#define A5A_IN P10_IN.B.P7

#define A12A_IN P20_IN.B.P9
#define A12B_IN P33_IN.B.P10
#define A13A_IN P33_IN.B.P11
#define A14A_IN P20_IN.B.P7
#define A15A_IN P20_IN.B.P8


/* Fast port access macros */
#define Fast_digitalWriteAB(port, val) 	(port##_OUT=val)
#define Fast_digitalReadAB(port) 		(port##_IN)

//#define Fast_digitalWrite(port, val) (D##port##_OUT=val)
#define Fast_digitalRead(port) 		 (D##port##_IN)

/* Superfast Pin Access Definitions */
#define D0_OMSR 	P15_OMSR.U
#define D0_OMCR 	P15_OMCR.U
#define D0_index 	3

#define D1_OMSR 	P15_OMSR.U
#define D1_OMCR 	P15_OMCR.U
#define D1_index 	2

#define D2_OMSR 	P02_OMSR.U
#define D2_OMCR 	P02_OMCR.U
#define D2_index 	0

#define D3_OMSR 	P02_OMSR.U
#define D3_OMCR 	P02_OMCR.U
#define D3_index 	1

#define D4_OMSR 	P10_OMSR.U
#define D4_OMCR 	P10_OMCR.U
#define D4_index 	4

#define D5_OMSR 	P02_OMSR.U
#define D5_OMCR 	P02_OMCR.U
#define D5_index 	3

#define D6_OMSR 	P02_OMSR.U
#define D6_OMCR 	P02_OMCR.U
#define D6_index 	4

#define D7_OMSR 	P02_OMSR.U
#define D7_OMCR 	P02_OMCR.U
#define D7_index 	5

#define D8_OMSR 	P02_OMSR.U
#define D8_OMCR 	P02_OMCR.U
#define D8_index 	6

#define D9_OMSR 	P02_OMSR.U
#define D9_OMCR 	P02_OMCR.U
#define D9_index 	7

#define D10_OMSR 	P10_OMSR.U
#define D10_OMCR 	P10_OMCR.U
#define D10_index 	5

#define D11_OMSR 	P10_OMSR.U
#define D11_OMCR 	P10_OMCR.U
#define D11_index 	3

#define D12_OMSR 	P10_OMSR.U
#define D12_OMCR 	P10_OMCR.U
#define D12_index 	1

#define D13_OMSR 	P10_OMSR.U
#define D13_OMCR 	P10_OMCR.U
#define D13_index 	2

#define D14_OMSR 	P15_OMSR.U
#define D14_OMCR 	P15_OMCR.U
#define D14_index 	0

#define D15_OMSR 	P15_OMSR.U
#define D15_OMCR 	P15_OMCR.U
#define D15_index 	1

#define D16_OMSR 	P33_OMSR.U
#define D16_OMCR 	P33_OMCR.U
#define D16_index 	9

#define D17_OMSR 	P33_OMSR.U
#define D17_OMCR 	P33_OMCR.U
#define D17_index 	8

#define D18_OMSR 	P20_OMSR.U
#define D18_OMCR 	P20_OMCR.U
#define D18_index 	0

#define D19_OMSR 	P20_OMSR.U
#define D19_OMCR 	P20_OMCR.U
#define D19_index 	3

#define D20_OMSR 	P20_OMSR.U
#define D20_OMCR 	P20_OMCR.U
#define D20_index 	4

#define D21_OMSR 	P20_OMSR.U
#define D21_OMCR 	P20_OMCR.U
#define D21_index 	5

#define D22_OMSR 	P14_OMSR.U
#define D22_OMCR 	P14_OMCR.U
#define D22_index 	0

#define D23_OMSR 	P14_OMSR.U
#define D23_OMCR 	P14_OMCR.U
#define D23_index 	1

#define D24_OMSR 	P15_OMSR.U
#define D24_OMCR 	P15_OMCR.U
#define D24_index 	6

#define D25_OMSR 	P00_OMSR.U
#define D25_OMCR 	P00_OMCR.U
#define D25_index 	0

#define D26_OMSR 	P00_OMSR.U
#define D26_OMCR 	P00_OMCR.U
#define D26_index 	8

#define D27_OMSR 	P00_OMSR.U
#define D27_OMCR 	P00_OMCR.U
#define D27_index 	1

#define D28_OMSR 	P00_OMSR.U
#define D28_OMCR 	P00_OMCR.U
#define D28_index 	9

#define D29_OMSR 	P00_OMSR.U
#define D29_OMCR 	P00_OMCR.U
#define D29_index 	2

#define D30_OMSR 	P00_OMSR.U
#define D30_OMCR 	P00_OMCR.U
#define D30_index 	10

#define D31_OMSR 	P00_OMSR.U
#define D31_OMCR 	P00_OMCR.U
#define D31_index 	3

#define D32_OMSR 	P00_OMSR.U
#define D32_OMCR 	P00_OMCR.U
#define D32_index 	11

#define D33_OMSR 	P00_OMSR.U
#define D33_OMCR 	P00_OMCR.U
#define D33_index 	4

#define D34_OMSR 	P00_OMSR.U
#define D34_OMCR 	P00_OMCR.U
#define D34_index 	12

#define D35_OMSR 	P00_OMSR.U
#define D35_OMCR 	P00_OMCR.U
#define D35_index 	5

#define D36_OMSR 	P33_OMSR.U
#define D36_OMCR 	P33_OMCR.U
#define D36_index 	2

#define D37_OMSR 	P00_OMSR.U
#define D37_OMCR 	P00_OMCR.U
#define D37_index 	6

#define D38_OMSR 	P33_OMSR.U
#define D38_OMCR 	P33_OMCR.U
#define D38_index 	1

#define D39_OMSR 	P00_OMSR.U
#define D39_OMCR 	P00_OMCR.U
#define D39_index 	7

#define D40_OMSR 	P33_OMSR.U
#define D40_OMCR 	P33_OMCR.U
#define D40_index 	0

#define D41_OMSR 	P11_OMSR.U
#define D41_OMCR 	P11_OMCR.U
#define D41_index 	9

#define D42_OMSR 	P11_OMSR.U
#define D42_OMCR 	P11_OMCR.U
#define D42_index 	3

#define D43_OMSR 	P11_OMSR.U
#define D43_OMCR 	P11_OMCR.U
#define D43_index 	11

#define D44_OMSR 	P33_OMSR.U
#define D44_OMCR 	P33_OMCR.U
#define D44_index 	3

#define D45_OMSR 	P11_OMSR.U
#define D45_OMCR 	P11_OMCR.U
#define D45_index 	2

#define D46_OMSR 	P11_OMSR.U
#define D46_OMCR 	P11_OMCR.U
#define D46_index 	3

#define D47_OMSR 	P11_OMSR.U
#define D47_OMCR 	P11_OMCR.U
#define D47_index 	6

#define D48_OMSR 	P21_OMSR.U
#define D48_OMCR 	P21_OMCR.U
#define D48_index 	3

#define D49_OMSR 	P21_OMSR.U
#define D49_OMCR 	P21_OMCR.U
#define D49_index 	0

#define D50A_OMSR 	P21_OMSR.U
#define D50A_OMCR 	P21_OMCR.U
#define D50A_index 	2

#define D51A_OMSR 	P13_OMSR.U
#define D51A_OMCR 	P13_OMCR.U
#define D51A_index 	3

#define D52A_OMSR 	P15_OMSR.U
#define D52A_OMCR 	P15_OMCR.U
#define D52A_index 	8

#define D53A_OMSR 	P20_OMSR.U
#define D53A_OMCR 	P20_OMCR.U
#define D53A_index 	10

#define D54_OMSR 	P13_OMSR.U
#define D54_OMCR 	P13_OMCR.U
#define D54_index 	2

#define D55_OMSR 	P13_OMSR.U
#define D55_OMCR 	P13_OMCR.U
#define D55_index 	1

#define Fast_digitalWrite(pin, val) (val==1)?(D##pin##_OMSR=(1<<D##pin##_index)):(D##pin##_OMCR=(0x00010000ul<<D##pin##_index));


/*
 * DACC
 */
#define DACC_INTERFACE		DACC
#define DACC_INTERFACE_ID	ID_DACC
#define DACC_RESOLUTION		12
#define DACC_ISR_HANDLER    DACC_Handler
#define DACC_ISR_ID         DACC_IRQn

/*
 * PWM
 */
#define PWM_INTERFACE		PWM
#define PWM_INTERFACE_ID	ID_PWM
#define PWM_FREQUENCY		1000
#define PWM_MAX_DUTY_CYCLE	255
#define PWM_MIN_DUTY_CYCLE	0
#define PWM_RESOLUTION		8

/*
 * TC
 */
#define TC_INTERFACE        TC0
#define TC_INTERFACE_ID     ID_TC0
#define TC_FREQUENCY        1000
#define TC_MAX_DUTY_CYCLE   255
#define TC_MIN_DUTY_CYCLE   0
#define TC_RESOLUTION		8

/* Interrupt priorities (visible globally) */
/* There are 255 levels 				   */
#define IFX_INTPRIO_INTERCORE_ISR	1
#define IFX_INTPRIO_STM0SRN0_ISR    255  /* Arduino tick system */
#define IFX_INTPRIO_STM0SRN1_ISR	3
#define IFX_INTPRIO_STM1SRN0_ISR	4
#define IFX_INTPRIO_STM2SRN0_ISR	5
#define IFX_INTPRIO_STM2SRN1_ISR	6
#define IFX_INTPRIO_STM1SRN1_ISR	7

#define IFX_INTPRIO_TIM_TPWM_ISR	8

#define ISR_PRIORITY_CCU6_PWMBC  	10

#define ISR_PRIORITY_SCUERU_0  		11

#define ISR_PRIORITY_TONE		  	12

//Priorities
#define IFX_INTPRIO_ASCLIN0_TX 		210
#define IFX_INTPRIO_ASCLIN0_RX 		211
#define IFX_INTPRIO_ASCLIN1_TX 		212
#define IFX_INTPRIO_ASCLIN1_RX 		213
#define IFX_INTPRIO_ASCLIN2_TX 		214
#define IFX_INTPRIO_ASCLIN2_RX 		215
#define IFX_INTPRIO_ASCLIN3_TX 		216
#define IFX_INTPRIO_ASCLIN3_RX 		217

#define IFX_INTPRIO_QSPI3_TX  		218
#define IFX_INTPRIO_QSPI3_RX  		219
#define IFX_INTPRIO_QSPI3_ER  		220
#define IFX_INTPRIO_QSPI2_TX  		221
#define IFX_INTPRIO_QSPI2_RX  		222
#define IFX_INTPRIO_QSPI2_ER  		223
#define IFX_INTPRIO_QSPI1_TX  		224
#define IFX_INTPRIO_QSPI1_RX  		225
#define IFX_INTPRIO_QSPI1_ER  		226

#define IFX_INTPRIO_GPT120_T6SPRN	228
#define IFX_INTPRIO_GPT120_T5SPRN	229 /* Must be higher */

#define IFX_INTPRIO_VADCGTM_TRIG	230 /* Only used when GTM triggers VADC */

#define IFX_INTPRIO_GENTIMER0		240
#define IFX_INTPRIO_GENTIMER1		241
#define IFX_INTPRIO_GENTIMER2		242
#define IFX_INTPRIO_GENTIMER3		243
#define IFX_INTPRIO_GENTIMER4		244
#define IFX_INTPRIO_GENTIMER5		245
#define IFX_INTPRIO_GENTIMER6		246
#define IFX_INTPRIO_GENTIMER7		247
#define IFX_INTPRIO_GENTIMER8		248
#define IFX_INTPRIO_GENTIMER9		249

#define IFX_INTPRIO_NEOPIXEL		250
#define IFX_INTPRIO_NEOPIXEL_C0		250
#define IFX_INTPRIO_NEOPIXEL_C1		251
#define IFX_INTPRIO_NEOPIXEL_C2		252

/* Aurix-specific functions */
/* Return the ID Of this core */
#define GetCpuCoreID()  (_mfcr(CPU_CORE_ID) & 0x07UL)

/* Control core startup */
typedef enum { CORE0_NOT_INITIALISED, CORE0_INITIALISED } Core0InitialisedType;
extern Core0InitialisedType volatile Core0Initialised;

#define ShieldBuddyVersion  ShieldBuddy_Version
#define ShieldBuddyDate  	ShieldBuddy_Date

/* Macros for controlling shared resources */
/* defines for Semaphore/s */
#define Htx_RESOURCE_BUSY (1U)
#define Htx_RESOURCE_FREE (0U)

#define E_NOT_OK 	1u
#define E_OK 		0u

/* Compare and if true, set to new value in a single instruction */
#define  Htx_CmpAndSwap(ResourceStatusPtr,Value,Compare)  \
        cmpswap_w(((unsigned int volatile*)(void*)ResourceStatusPtr), ((unsigned int)Value), ((unsigned int)Compare) )

extern uint32 Htx_LockResource(uint32 *ResourcePtr);
extern void  Htx_UnlockResource(uint32* ResourcePtr);
extern uint32 Htx_GetSpinLock(uint32* SpinLckPtr,uint32 Timeout);
extern void Htx_ReleaseSpinLock(uint32* SpinLckPtr);

/* Macros for creating interrupts in another core */
#define InterruptCore0() SRC_GPSR_GPSR0_SR0.B.SETR=1
#define InterruptCore1() SRC_GPSR_GPSR0_SR1.B.SETR=1
#define InterruptCore2() SRC_GPSR_GPSR0_SR2.B.SETR=1


extern void CreateInterrupt(uint8 TargetCoreID, uint16 Priority, void (*CoreXinthandler)(void));
extern void CreateCore0Interrupt(void (*CoreXinthandler)(void));
extern void CreateCore1Interrupt(void (*CoreXinthandler)(void));
extern void CreateCore2Interrupt(void (*CoreXinthandler)(void));

/* Get a snapshot of STM0 */
#define GetCurrentNanoSecs()  STM0_TIM0.U

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include "WCharacter.h"

#include "HardwareSerial.h"
#include "HardwareSerial0.h"
#include "HardwareSerial1.h"
#include "HardwareSerialRxTx.h"

/* Allow shield drivers like MIDI to use RX TX serial port on ShieldBuddy */
#define HardwareSerial SerialClassRxTx

extern SerialClass3 SerialASC;  /* Arduino FDTI USB-COM          */
extern SerialClass2 Serial1; 	/* RX1/TX1 Arduino J403 17/16	 */
extern SerialClass1 Serial0; 	/* RX0/TX0 Arduino J403 15/14	 */
extern SerialClassRxTx Serial; 	/* RX/TX Arduino J402 D0/D1	     */


extern void asclin0TxISR(int i);
extern void asclin0RxISR(int i);
extern void asclin0ErISR(int i);

extern void asclin1TxISR(int i);
extern void asclin1RxISR(int i);
extern void asclin1ErISR(int i);

extern uint32 volatile CpuClock;
extern uint32 volatile SysClock;
extern uint32 volatile StmClock;

// Check CSA free space
extern uint16 CheckFreeCSA_Size(void);

extern uint16 volatile Core0_CsaFreeSpace;
extern uint16 volatile Core1_CsaFreeSpace;
extern uint16 volatile Core2_CsaFreeSpace;

extern void printfASC(const char *format, ... );

#endif


#endif


