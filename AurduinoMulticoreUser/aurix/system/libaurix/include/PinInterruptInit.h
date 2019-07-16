#ifndef PININTERRUPTINIT_H
#define PININTERRUPTINIT_H



#ifdef __cplusplus
extern "C" {
#endif


/* Edge triggering modes */
typedef uint8 Htx_PinIntConfigType;

/* Function Pointer Type for ERU pin interrupt */
typedef void (*PortInterruptCallBackType)(void);

/**
 *
 * This function is called from setup()
 *                  Pin Number, Interrupt function name, Pin Mode (RISING, FALLING, CHANGE)
 * void attachInterrupt(uint8 PinNo, PortInterruptCallBackType Inthandler, Htx_PinIntConfigType EdgeSensitivity)
 */
extern void attachInterrupt(uint8 PinNo, PortInterruptCallBackType Inthandler, Htx_PinIntConfigType EdgeSensitivity);
extern void detachInterrupt(uint8 PinNo);

#ifdef __cplusplus
}
#endif

#endif /* PININTERRUPTINIT_H */
