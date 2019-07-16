/*
 * analogOut.h
 *
 *  Created on: 23 Apr 2015
 *      Author: mbeach
 */

#ifndef ANALOGOUT_H_
#define ANALOGOUT_H_

/* Direct access to DR SFR */
#define AnalogOut_2_DutyRatio				(GTM_ATOM0_CH0_SR1.U)
#define AnalogOut_3_DutyRatio				(GTM_ATOM0_C19_SR1.U)
#define AnalogOut_4_DutyRatio				(GTM_ATOM0_CH6_SR1.U)
#define AnalogOut_5_DutyRatio				(GTM_ATOM0_CH3_SR1.U)
#define AnalogOut_6_DutyRatio				(GTM_ATOM0_CH4_SR1.U)
#define AnalogOut_7_DutyRatio				(GTM_ATOM0_CH5_SR1.U)
#define AnalogOut_8_DutyRatio				(GTM_ATOM1_CH6_SR1.U)
#define AnalogOut_9_DutyRatio				(GTM_ATOM0_CH7_SR1.U)
#define AnalogOut_10_DutyRatio				(GTM_ATOM4_CH2_SR1.U)
#define AnalogOut_11_DutyRatio				(GTM_ATOM1_CH3_SR1.U)
#define AnalogOut_12_DutyRatio				(GTM_ATOM1_CH1_SR1.U)

#define AnalogOutDAC0_DutyRatio				(GTM_ATOM2_CH0_SR1.U)
#define AnalogOutDAC1_DutyRatio				(GTM_ATOM0_CH2_SR1.U)

#define AnalogOutDAC0_RF_DutyRatio  		(GTM_ATOM2_CH0_SR1.U)
#define AnalogOutDAC1_RF_DutyRatio  		(GTM_ATOM0_CH2_SR1.U)
#define AnalogOutDAC0_RF_270kHzCarrier  	(370)	// 270kHz
#define AnalogOutDAC1_RF_529kHzCarrier  	(189)  	// 529kHz

/* Allow analogWrite(x,y) to initialise channel again.
 * Used when the PWM frequency needs to be changed
 * in real time.
 */
#define AnalogOut_2_Reset()		P02_IOCR0.B.PC0 = 2
#define AnalogOut_3_Reset()		P02_IOCR0.B.PC1 = 2
#define AnalogOut_4_Reset()		P10_IOCR4.B.PC4 = 2
#define AnalogOut_5_Reset()		P02_IOCR0.B.PC3 = 2
#define AnalogOut_6_Reset()		P02_IOCR4.B.PC4 = 2
#define AnalogOut_7_Reset()		P02_IOCR4.B.PC5 = 2
#define AnalogOut_8_Reset()		P02_IOCR4.B.PC6 = 2
#define AnalogOut_9_Reset()		P02_IOCR4.B.PC7 = 2
#define AnalogOut_10_Reset()	P10_IOCR4.B.PC5 = 2
#define AnalogOut_11_Reset()	P10_IOCR0.B.PC3 = 2
#define AnalogOut_12_Reset()	P10_IOCR0.B.PC1 = 2

#define Resolution8Bit						((uint32) 1u << 8u)
#define Resolution10Bit						((uint32) 1u << 10u)
#define Resolution12Bit						((uint32) 1u << 12u)
#define Resolution14Bit						((uint32) 1u << 14u)
#define Resolution16Bit						((uint32) 1u << 16u)
#define Resolution24Bit						((uint32) 1u << 24u)

extern uint32 CMU_CLK4_val;

/* Function Prototypes */
extern void useArduinoPwmFreq(void);
extern void useCustomPwmFreq(uint32 CustomPwmFreq);
extern void setupGtmClocks(void);
extern void setupGtmTbu (void);
extern void Gtm_analogWrite(uint32 ulPin, uint32 ulValue);


#endif /* ANALOGOUT_H_ */
