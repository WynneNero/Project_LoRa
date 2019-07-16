/*
 * NeopixelDriver.h
 *
 *  Created on: 28 Jun 2017
 *      Author: mbeach
 */

#ifndef NEOPIXELDRIVER_H_
#define NEOPIXELDRIVER_H_

#include "NeoPixel_Cfg.h"

#define NUMBER_OF_CORES 			(3)

typedef struct { uint8 ResetTimeout;
				 uint32 *NeoPixel_SR1;
				 uint32 *NeoPixel_IrqNotify;
				 uint8 *p;
				 uint8 *end;
				 uint8 pix;
				 uint8 mask;} NeoPixelType;

extern uint32 volatile NeoPixels_ResetTimeout;

extern NeoPixelType volatile NeoPixel[NoOfAURduinoPins];
extern void NeoPixelGtmHandler(uint8 pin);

/* Externs */
#ifdef __cplusplus
extern "C"{
#endif

extern uint8 const NeoPixel_Zero_DR;
extern uint8 const NeoPixel_One_DR;
extern uint8 const NeoPixel_Low_DR;
extern uint8 const NeoPixel_ResetTimeout;

#ifdef __cplusplus
}
#endif

#endif /* NEOPIXELDRIVER_H_ */
