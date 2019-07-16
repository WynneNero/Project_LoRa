/*
 * SbCheck.h
 *
 *  Created on: 27 Mar 2018
 *      Author: MBeach
 */

#ifndef _SBCHECK_H_
#define _SBCHECK_H_

#ifdef __cplusplus

/* Export checking function */
extern "C" void checkShieldBuddy(void);

#else

/* Export checking function */
extern void checkShieldBuddy(void);

#endif


#endif /* _SBCHECK_H_ */
