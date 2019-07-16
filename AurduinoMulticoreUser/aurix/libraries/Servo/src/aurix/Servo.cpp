/*
  Copyright (c) 2013 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#if defined(ARDUINO_ARCH_AURIX )

#include <Arduino.h>
#include <Servo.h>

#define clockCyclesPerMicrosecond()   25u

#define usToTicks(_us)    (( clockCyclesPerMicrosecond() * _us) )     // converts microseconds to tick
#define ticksToUs(_ticks) (( (unsigned)_ticks)/ clockCyclesPerMicrosecond() ) // converts from ticks back to microseconds

#define TRIM_DURATION       2                               // compensation ticks to trim adjust for digitalWrite delays

static servo_t servos[MAX_SERVOS];                          // static array of servo structures

uint8_t ServoCount = 0;                                     // the total number of attached servos

static volatile int8_t Channel[_Nbr_16timers ];             // counter for the servo being pulsed for each timer (or -1 if refresh interval)

static uint32 Slots = 0;
static uint8 volatile Flasher;
static uint16 ThisSlot = 0;

// convenience macros
#define SERVO_INDEX_TO_TIMER(_servo_nbr) ((timer16_Sequence_t)(_servo_nbr / SERVOS_PER_TIMER)) // returns the timer controlling this servo
#define SERVO_INDEX_TO_CHANNEL(_servo_nbr) (_servo_nbr % SERVOS_PER_TIMER)       // returns the index of the servo on this timer
#define SERVO_INDEX(_timer,_channel)  ((_timer*SERVOS_PER_TIMER) + _channel)     // macro to access servo index by timer and channel
#define SERVO(_channel)  (servos[_channel])            // macro to access servo class by timer and channel

#define SERVO_MIN() (MIN_PULSE_WIDTH - this->min * 4)  // minimum value in uS for this servo
#define SERVO_MAX() (MAX_PULSE_WIDTH - this->max * 4)  // maximum value in uS for this servo


/************ static functions common to all instances ***********************/

//------------------------------------------------------------------------------
/// Interrupt handler for the TC0 channel 1.
//------------------------------------------------------------------------------
void Servo_Handler(int i);

/* Entered every 30ms off T5 */
/* Note: this needs to be at a very high priority */
void Servo_Handler(int i)
{
	/* digitalWrite(servos[ThisSlot].Pin.nbr, LOW); // pulse this channel low if activated */

	/* Fastest possible pin access - set low */
	IfxPort_setPinState(AURduinoPins[servos[ThisSlot].Pin.nbr].port, AURduinoPins[servos[ThisSlot].Pin.nbr].pinIndex, IfxPort_State_low);

	GPT120_T5CON.B.T5R = 0 ; // Stop timer 5

}


/* Entered every 2.5ms */
void Servo_Slot_Handler(int i)
{

	//digitalWrite(13,Flasher ^= 1);  // For testing

	/* Schedule servo channel interrupt */

	/* Make sure T5 is stopped */
	GPT120_T5.U = 0u;

	/* If servo channel is active, turn pin ON */
	if(servos[Slots].Pin.isActive == true)
	{    // check if activated

		/* Schedule a pin off interrupt in ticks time */
		GPT120_T5.U = servos[Slots].ticks ;
	    GPT120_T5CON.B.T5R = 1 ;

		/* digitalWrite(servos[Slots].Pin.nbr,HIGH); // its an active channel so pulse it high */

		/* Fastest possible pin access - set high */
		IfxPort_setPinState(AURduinoPins[servos[Slots].Pin.nbr].port, AURduinoPins[servos[Slots].Pin.nbr].pinIndex, IfxPort_State_high);

		/* Capture slot number for use by pin off interrupt */
		ThisSlot = Slots;

	}
	else
	{
		   GPT120_T5CON.B.T5R = 0;
	}


	/* Manage slot counter */
	Slots++;
	if(Slots >= MAX_SERVOS)
	{
		Slots = 0u;
	}
}



/* Start a timer */
static void initISR(timer16_Sequence_t timer)
{
	/* Setup the 2.5ms interrupt */

    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());

    while(GPT120_CLC.B.DISS == 1u)
    {

    	GPT120_CLC.B.DISR = 0u;
    }

    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());


    /* Setup T5 for PWM update timebase */
    /* Fin = 3.2MHz */
    GPT120_T5CON.U = 0x0001 ;  // 40ns/count  0.3125 us per count
    GPT120_T5CON.B.T5UD = 1 ;  // T5 counts down

	/* install interrupt handler */
	_install_int_handler(IFX_INTPRIO_GPT120_T5SPRN, Servo_Handler, 0);
    SRC_GPT120T5.U = (GetCpuCoreID() << 11u) |(1u << 10u) | (IFX_INTPRIO_GPT120_T5SPRN << 0u);

	GPT120_T5.U = 62500u;
    GPT120_T5CON.B.T5R = 0 ; /* Do not start Timer5 yet */

    /* Timer 6 */
    GPT120_T6.U = 6250u; /* First interrupt in 500us */
    GPT120_CAPREL.U = 31250u; /* 12500 = 1ms, 31250 = 2.5ms, 80ns/count */
    GPT120_T6CON.U = (3u << 11) | (1u << 15u) | (1u << 7u) | 2; /* T6 reload from CAPREL, T6 counts down */
    GPT120_T6CON.B.BPS2 = 1 ;  /* Double speed */

	/* install interrupt handler */
	_install_int_handler(IFX_INTPRIO_GPT120_T6SPRN, Servo_Slot_Handler, 0);
    SRC_GPT120T6.U = (GetCpuCoreID() << 11u) |(1u << 10u) | (IFX_INTPRIO_GPT120_T6SPRN << 0u);

    GPT120_T6CON.B.T6R = 1u;

}

/* Stop a timer */
static void finISR(timer16_Sequence_t timer)
{
	/* Stop the STM interrupt */

}


static boolean isTimerActive(timer16_Sequence_t timer)
{
  // returns true if any servo is active on this timer
  for(uint8_t channel=0; channel < SERVOS_PER_TIMER; channel++) {
    if(servos[channel].Pin.isActive == true)
      return true;
  }
  return false;
}

/****************** end of static functions ******************************/

Servo::Servo()
{
  if (ServoCount < MAX_SERVOS) {
    this->servoIndex = ServoCount++;                    // assign a servo index to this instance
    servos[this->servoIndex].ticks = usToTicks(DEFAULT_PULSE_WIDTH);   // store default values
  } else {
    this->servoIndex = INVALID_SERVO;  // too many servos
  }
}

uint8_t Servo::attach(int pin)
{
  return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t Servo::attach(int pin, int min, int max)
{
	timer16_Sequence_t timer;
	uint32 i;

	if (this->servoIndex < MAX_SERVOS)
	{
		pinMode(pin, OUTPUT);                                   // set servo pin to output
		servos[this->servoIndex].Pin.nbr = pin;
		// todo min/max check: abs(min - MIN_PULSE_WIDTH) /4 < 128
		this->min  = (MIN_PULSE_WIDTH - min)/4; //resolution of min/max is 4 uS
		this->max  = (MAX_PULSE_WIDTH - max)/4;
		// initialize the timer if it has not already been initialized

		if(GPT120_T6CON.B.T6R == 0u)
		{
			initISR(timer);  // Parameter no longer used
		}

		servos[this->servoIndex].Pin.isActive = true;  // this must be set after the check for isTimerActive

		/* Initialise unused slots to max time */
		for(i = 0 ; i < MAX_SERVOS ; i++)
		{

			/* Make sure unused channels are at max timeout value */
			if(servos[i].Pin.isActive == false)
			{
				servos[i].ticks = 0xFFFFu;
			}

		}
	}

  return this->servoIndex;
}

void Servo::detach()
{
  //timer16_Sequence_t timer;

  servos[this->servoIndex].Pin.isActive = false;

  /* Set timeout to max for this slot */
  servos[this->servoIndex].ticks = 0xFFFFu;

  //timer = SERVO_INDEX_TO_TIMER(servoIndex);
 // if(isTimerActive(timer) == false) {
 //   finISR(timer);
//  }
}

void Servo::write(int value)
{
  // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
  if (value < MIN_PULSE_WIDTH)
  {
    if (value < 0)
      value = 0;
    else if (value > 180)
      value = 180;

    value = map(value, 0, 180, SERVO_MIN(), SERVO_MAX());
  }
  writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value)
{

	// calculate and store the values for the given channel
	byte channel = this->servoIndex;
	if( (channel < MAX_SERVOS) )   // ensure channel is valid
	{
		if (value < SERVO_MIN())          // ensure pulse width is valid
		{
			value = SERVO_MIN();
		}
		else if (value > SERVO_MAX())
		{
			value = SERVO_MAX();
		}

    value = value - TRIM_DURATION;
    value = usToTicks(value);  // convert to ticks after compensating for interrupt overhead
    servos[channel].ticks = value;
	}
}

int Servo::read() // return the value as degrees
{
  return map(readMicroseconds()+1, SERVO_MIN(), SERVO_MAX(), 0, 180);
}

int Servo::readMicroseconds()
{
  unsigned int pulsewidth;
  if (this->servoIndex != INVALID_SERVO)
    pulsewidth = ticksToUs(servos[this->servoIndex].ticks)  + TRIM_DURATION;
  else
    pulsewidth  = 0;

  return pulsewidth;
}

bool Servo::attached()
{
  return servos[this->servoIndex].Pin.isActive;
}

#endif // ARDUINO_ARCH_AURIX

