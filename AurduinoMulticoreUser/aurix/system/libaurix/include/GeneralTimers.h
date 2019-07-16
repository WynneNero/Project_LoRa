

#ifndef GENERALTIMERS_H
#define GENERALTIMERS_H

typedef struct { uint8 Atom;
				 uint8 AtomChannel;
				 uint8 IntPriority;
				 void (*inthandler)(int);
				 void (*user_inthandler)(int);
} TimerChannelConfigType;

typedef enum { GeneralTimersGTMNotInitialised, GeneralTimersGTMInitialised } GeneralTimersGtmInitType ;

/* Uses otherwise idle ATOMs */
extern TimerChannelConfigType TimerChannelConfig[9];

extern uint32 GetAtomTimerChannelCount(uint8 TimerChannel);
extern void EnableTimerChannelInt(uint8 TimerChannel);
extern void DisableTimerChannelInt(uint8 TimerChannel);
extern void InitialiseAtomTimer(uint8 Atom, uint8 AtomChannel, int IntPriority,  void (*inthandler)(int));
extern void SetAtomTimerPeriod(uint8 Atom, uint8 AtomChannel, uint32 Period);
extern void SetTimerChannelPeriod(uint8 TimerChannel, uint32 Period);
extern void InitialiseTimerChannel(uint8 Channel);

#endif /* GENERALTIMERS_H */
