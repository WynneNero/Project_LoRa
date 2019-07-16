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

#ifndef VADCGTM_H_
#define VADCGTM_H_


void SetVadcResVadcGtm(uint16 VadcResolution);

void VadcGtmInit(void);

void VadcGtmTrigInit(uint32 VADC_TriggerFrequency);



#endif /* VADCGTM_H_ */
