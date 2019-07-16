

/*
 * This header file contains variables/defines/data etc that is
 * global to the arduino framework and is not specific to a
 * particular chip.
 */


#ifndef _ARDUINO_H
#define _ARDUINO_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#ifdef __cplusplus
extern "C"{
#endif // _cplusplus

#include "wiring_constants.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
#include "wiring.h"

void yield(void);

#ifdef __cplusplus
}
//#include "WCharacter.h"

#include "WString.h"
#include "Tone.h"
#include "WMath.h"
#include "HardwareSerial.h"
#include "HardwareSerial0.h"
#include "HardwareSerial1.h"
#include "HardwareSerialRxTx.h"
//#include "wiring_pulse.h"
#endif // _cplusplus

#include "variant.h"

#include "wiring.h"
#include "wiring_digital.h"
//#include "wiring_analog.h"
#include "wiring_shift.h"
//#include "WInterrupts.h"




#endif
