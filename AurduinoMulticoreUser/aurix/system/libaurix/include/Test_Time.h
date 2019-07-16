/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Test_Time.h $                                              **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-09-23 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of                        **
**                System Timer Module.                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/


#ifndef TEST_TIME_H
#define TEST_TIME_H

extern uint32 uwSysFreq;
extern uint32 uwPerFreq;



#define STM_SETALARM_API 

#ifdef STM_SETALARM_API
/* Load Value for the Counter Compare register */
extern uint32 Count_Timer_Core0[2];
extern uint32 Count_Timer_Core1[2];
extern uint32 Count_Timer_Core2[2];

extern void (*TestTime_ArrayFnp_Core0[2])(void);
extern void (*TestTime_ArrayFnp_Core1[2])(void);
extern void (*TestTime_ArrayFnp_Core2[2])(void);

/*Variable to hold the Mode of alarm ID 0 and 1 at 0  and 1st bit respectively*/
extern uint8 TestTime_AlarmMode_Core0;
extern uint8 TestTime_AlarmMode_Core1;
extern uint8 TestTime_AlarmMode_Core2;
#endif

#define Clk_Freq       (120000000) /* Hz */
#define SysFreq         (uwSysFreq) /* Hz */
#define SysFreqKhz   ( (SysFreq + 500) / 1000 )

#define ReqTimeMs       (uwReqTimeMs)

/* Macro to get time in milli seconds from the timer count */
#define TIME_100NS(cycles) (uint32)(((long )cycles * 10000 + SysFreqKhz/2) \
                                      /SysFreqKhz)

/* Macro to get Load Value from the time in milli seconds */
#define Count_Timer_Core0(ReqTimeMs)   (uint32)((SysFreqKhz) * (ReqTimeMs))

/* STM Init Function */
extern void Test_InitTime_Core0(void);
extern void Test_InitTime_Core1(void);
extern void Test_InitTime_Core2(void);

/*extern void STM_ISR_SR0(void);*/
extern void STM0SRN1_ISR();


#ifdef STM_SETALARM_API

/* STM Test Function */
extern void STM_SetEvent_Core0(uint8 AlarmId,uint8 AlarmMode,uint32 ReqTimeStmCycles,\
                                void (*Test_Time_CallFnpp)(void));

extern void STM_SetEvent_Core1(uint8 AlarmId,uint8 AlarmMode,uint32 ReqTimeStmCycles,\
                                void (*Test_Time_CallFnpp)(void));

extern void STM_SetEvent_Core2(uint8 AlarmId,uint8 AlarmMode,uint32 ReqTimeStmCycles,\
                                void (*Test_Time_CallFnpp)(void));

#define OneShotTimerInterrupt  		1u
#define ContinuousTimerInterrupt  	0u

/* Create a timer event with a timing of cycles * 10us */
#define CreateTimerInterrupt(mode, cycles, CallFnpp)  STM_SetEvent_Core0(1, mode, cycles, CallFnpp)
#define CreateTimerInterrupt1_Core0(mode, cycles, CallFnpp)  STM_SetEvent_Core0(1, mode, cycles, CallFnpp)
#define CreateTimerInterrupt0_Core1(mode, cycles, CallFnpp)  STM_SetEvent_Core1(0, mode, cycles, CallFnpp)
#define CreateTimerInterrupt1_Core1(mode, cycles, CallFnpp)  STM_SetEvent_Core1(1, mode, cycles, CallFnpp)
#define CreateTimerInterrupt0_Core2(mode, cycles, CallFnpp)  STM_SetEvent_Core2(0, mode, cycles, CallFnpp)
#define CreateTimerInterrupt1_Core2(mode, cycles, CallFnpp)  STM_SetEvent_Core2(1, mode, cycles, CallFnpp)

/* STM DeInit Function */
extern void Test_Time_DeInitAlarm_Core0(uint8 AlarmId);
extern void Test_Time_DeInitAlarm_Core1(uint8 AlarmId);
extern void Test_Time_DeInitAlarm_Core2(uint8 AlarmId);

/* STM Delay Function */
//extern void Timer_DelayTicks_Core0(uint32 ReqTimeMs );
extern void Timer_DelayTicks_Core0(uint32 ReqTimeTicks );
extern void Timer_DelayTicks_Core1(uint32 ReqTimeTicks );

#endif

#endif /* End of File Test_Time.h */

