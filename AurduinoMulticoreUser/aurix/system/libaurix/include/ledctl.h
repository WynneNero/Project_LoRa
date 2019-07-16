/*! \file ledctl.h
 *  \brief Simple LED control API definition
 *
 *  A simple LED control API providing functions to control single or all
 *  LEDs of a board.
 *
 *  \autor TGL
 *
 *  \version
 *    08.08.2010  initial version
 */

#ifndef __LEDCTL_H__
#define __LEDCTL_H__

#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

/*! \brief Initialize LED port
 *  \return Number of LEDs
 */
int LEDCTL_Init(void);

/*! \brief Cleanup all LED pins
 */
void LEDCTL_Cleanup(void);

/*! \brief Get number of LEDs
 */
int  LEDCTL_GetCount(void);

/*! \brief Switch a single LED on
 *  \param Index of LED to control
 */
void LEDCTL_On(int Index);

/*! \brief Switch a single LED off
 *  \param Index of LED to control
 */
void LEDCTL_Off(int Index);

/*! \brief Get status of a single LED
 *  \param Index of LED to control
 *  \return
 *    0 ... LED is off
 *    1 ... LED is on
 */
int  LEDCTL_Status(int Index);

/*! \brief Toggle a single LED
 *  \param Index of LED to control
 */
void LEDCTL_Toggle(int Index);

/*! \brief Output value to LED port
 */
void LEDCTL_Out(unsigned int Value);

#ifdef __cplusplus
  }
#endif /* __cplusplus */

#endif /* __LEDCTL_H__ */
