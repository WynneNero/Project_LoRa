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
 *  Project     4293 Hitex DriverLib_TC23x
 * \file        Htx_PFlash_TC23x.h
 * \brief       PFlash driver device specific header file
 * \details     Contains device specific constants
 * \author      Hitex (UK) Ltd
 * \date        \$LastChangedDate:: 2016-03-14 #$
 * \version     \$Revision: 12222 $
 * \attention   -
 ******************************************************************************
 */

#ifndef HTX_PFLASH_TC23X_H
#define HTX_PFLASH_TC23X_H

/*
 ******************************************************************************
 * Standard include files
 ******************************************************************************
 */


/*
 ******************************************************************************
 * Project include files
 ******************************************************************************
 */


/*
 ******************************************************************************
 * Types
 ******************************************************************************
 */


 /*
 ******************************************************************************
 * Macro defines
 ******************************************************************************
 */

#define HTX_PFLASH_FLASH_BUSY_MASK         ((uint32)0xA)

#define HTX_PFLASH_NUM_OF_PF0_SECTORS      (27U)

#define HTX_PFLASH_PROCON_CHECK            ((uint32)(0x7FFFFFF))

#define HTX_PFLASH_PFLASH0_START_ADDRESS   ((Htx_PFlash_AddressType)(0xA0000000))


/*
 ******************************************************************************
 * Variable declarations
 ******************************************************************************
 */


/*
 ******************************************************************************
 * Routine prototypes
 ******************************************************************************
 */


#endif /* HTX_PFLASH_TC23X_H */

/* EOF */
/* Template version:    4.0         */
/* Template status:     RELEASED    */
