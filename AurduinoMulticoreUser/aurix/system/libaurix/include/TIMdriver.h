/*
 * TIMdriver.h
 *
 *  Created on: 2 May 2017
 *      Author: MBeach
 */

#ifndef _TIMDRIVER_H_
#define _TIMDRIVER_H_

#define TIM_TPWM_RISINGEDGE  	1u	/* Measure on rising edges  */
#define TIM_TPWM_FALLINGEDGE  	0u 	/* Measure on falling edges  */


typedef enum { NoPwmMeasurementData, PwmMeasurementData } MeasurePwmReturnType;

extern MeasurePwmReturnType MeasurePwm(uint8 _pin, uint32 *Period, uint32 *Duration, float *DutyRatio);
extern void Init_TIM_TPWM(uint8 _pin, boolean polarity);
extern float MeasureDutyRatio(uint8 _pin);
extern float MeasureFrequency(uint8 _pin);

#endif /* _TIMDRIVER_H_ */
