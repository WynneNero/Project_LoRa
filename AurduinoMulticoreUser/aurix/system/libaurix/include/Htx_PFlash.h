/**
 \verbatim
 ******************************************************************************
 * Copyright (c) Hitex (UK) Ltd., all rights reserved.
 ******************************************************************************
 * This source code and any compilation or derivative thereof is the sole 
 * property of Hitex (UK) Ltd. and is provided pursuant to a 
 * Software License  Agreement. This code is the proprietary information of 
 * Hitex (UK) Ltd. and is confidential in nature. Its use and 
 * dissemination by any other party other than Hitex (UK) Ltd. 
 * is strictly limited by the confidential information provisions of the 
 * Agreement referenced above.
 ******************************************************************************
 \endverbatim
 ******************************************************************************
 ******************************************************************************
 *  Project     4293 Hitex DriverLib_TC27x
 * \file        Htx_PFlash.h
 * \brief       PFlash driver header file
 * \details     PFlash driver header file
 * \author      Hitex (UK) Ltd
 * \date        \$LastChangedDate:: 2016-03-14 #$
 * \version     \$Revision: 12222 $
 * \attention   Functions provided by PFlash driver needs to be executed 
 *              from RAM
 ******************************************************************************
 */

#ifndef HTX_PFLASH_H
#define HTX_PFLASH_H

/*
 ******************************************************************************
 * Standard include files
 ******************************************************************************
 */
 
#include "Ifx_Types.h"

/*
 ******************************************************************************
 * Project include files
 ******************************************************************************
 */
 
#include "Htx_PFlash_UserCfg.h"
#include "Htx_PFlash_TC27x.h"

/*
 ******************************************************************************
 * Types
 ******************************************************************************
 */

/*
Type: Htx_PFlash_AddressType
This specifies the flash address
*/
typedef uint32 volatile Htx_PFlash_AddressType;

/*
Type: Htx_PFlash_LengthType
This specifies the Length/size to program/erase
*/
typedef uint32 Htx_PFlash_LengthType;

/*
Type: Htx_PFlash_ReturnType
This specifies the various Return values of the APIs
*/
typedef uint32 Htx_PFlash_ReturnType;

/*
 ******************************************************************************
 * Macro defines
 ******************************************************************************
 */

/* Flash operation successful */
#define HTX_PFLASH_OK              ((Htx_PFlash_ReturnType)0x0)
/* Flash operation failed */
#define HTX_PFLASH_NOT_OK          ((Htx_PFlash_ReturnType)0x1)
/* Flash sector is locked */
#define HTX_PFLASH_LOCKED          ((Htx_PFlash_ReturnType)0x2)
/* Flash sector is busy */
#define HTX_PFLASH_BUSY            ((Htx_PFlash_ReturnType)0x5)

#define HTX_PFLASH_MAX_SECTORS           ((uint32)27)

/*
 ******************************************************************************
 * Variable declarations
 ******************************************************************************
 */


extern uint32 Htx_PFlash_PFlashSectorOffset[HTX_PFLASH_MAX_SECTORS];

/*
 ******************************************************************************
 * Routine prototypes
 ******************************************************************************
 */
 
extern Htx_PFlash_ReturnType Htx_PFlash_Write(Htx_PFlash_AddressType TargetAddress,
                                              Htx_PFlash_LengthType Length,
                                              const uint8 *SourceAddressPtr);

extern Htx_PFlash_ReturnType Htx_PFlash_Erase(Htx_PFlash_AddressType TargetAddress,
                                              Htx_PFlash_LengthType Length);


#endif /* HTX_PFLASH_H */

/* EOF */
/* Template version:    4.0         */
/* Template status:     RELEASED    */
