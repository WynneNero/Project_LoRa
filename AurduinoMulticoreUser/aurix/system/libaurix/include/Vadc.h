/**
 \verbatim
 ******************************************************************************
 * Copyright (c) 2015 Hitex UK Ltd. All rights reserved.
 ******************************************************************************
 * Hitex UK Ltd. is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************
 \endverbatim
 ******************************************************************************
 *  Project     4269 Auxduino
 * \file 		Vadc.h
 * \brief 	    Vadc initialisation function definition
 * \details     Initialises VADC for spot readings
 * \author      Hitex (UK) Ltd
 * \date        \$LastChangedDate:: 2017-04-05 #$
 * \version     \$Revision: 1383 $
 * \attention   -
 ******************************************************************************
 */

#ifndef VADC_H_
#define VADC_H_

#define VADC_12BitConversion  	0u
#define VADC_10BitConversion  	1u
#define VADC_8BitConversion  	2u

/* Derived from experimentation */
#define Vadc12BitSampleTime    2u
#define Vadc10BitSampleTime    4u
#define Vadc8BitSampleTime     6u

#define NoOfVadcChannels  		16u

#define INTERNAL  				3u

/* Call AD reading functions via function pointers */
#define Read_ADx(AdcChannel) ReadADxFuncs[AdcChannel]()

typedef enum { LeftAlign, RightAlign } VadcResultAlignmentType;
//typedef enum { DEFAULT, INTERNAL, EXTERNAL } analogRefSourceType;

/* Set VADC Resolution */
void SetVadcRes(uint16 VadcResolution);

void VadcInit(void);
uint16 ReadAD0(void);
uint16 ReadAD1(void);
uint16 ReadAD2(void);
uint16 ReadAD3(void);
uint16 ReadAD4(void);
uint16 ReadAD5(void);
uint16 ReadAD6(void);
uint16 ReadAD7(void);
uint16 ReadAD8(void);
uint16 ReadAD9(void);
uint16 ReadAD10(void);
uint16 ReadAD11(void);
uint16 ReadAD12(void);
uint16 ReadAD13(void);
uint16 ReadAD14(void);
uint16 ReadAD15(void);

uint16 ReadCiC2v5Reference(void);
void analogReference(eAnalogReference);

uint16 ReadAD(uint8 pin);

typedef uint16 (*ReadADxFuncsType)(void);

extern ReadADxFuncsType const ReadADxFuncs[NoOfVadcChannels];

extern unsigned int uiResult[16];

#endif /* VADC_H_ */
