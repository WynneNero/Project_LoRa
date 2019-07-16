#include "arduino.h"

/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/
//#pragma GCC optimize "-O0"

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */

void UserTimer2Handler(int i)
{

   digitalWrite(13,!digitalRead(13));

}

void UserTimer3Handler(int i)
{

    digitalWrite(12,!digitalRead(12));
}

void UserTimer0Handler(int i)
{

    digitalWrite(11,!digitalRead(11));
}

void UserTimer4Handler(int i)
{

    digitalWrite(10,!digitalRead(10));
}


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	// Setup output pins
	pinMode(13,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(11,OUTPUT);
	pinMode(10,OUTPUT);

	// Set user handlers
	TimerChannelConfig[2].user_inthandler = UserTimer2Handler;
	TimerChannelConfig[3].user_inthandler = UserTimer3Handler;
	TimerChannelConfig[0].user_inthandler = UserTimer0Handler;

	// Initialise general timer channels
	InitialiseTimerChannel(2);
	InitialiseTimerChannel(3);
	InitialiseTimerChannel(0);

	// Set period of timers
	SetTimerChannelPeriod(2,0x8000);
	SetTimerChannelPeriod(3,0x4000);
	SetTimerChannelPeriod(0,100000);

}



void loop() {
  // put your main code for core 0 here, to run repeatedly:



}


/*** Core 1 ***/

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have no initial values here e.g. uint32 CPU1_var; */
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have an initial value here e.g. uint32 CPU1_var_init = 1; */
EndOfInitialised_CPU1_Variables

void setup1() {
  // put your setup code for core 1 here, to run once:

	// Create a periodic interrupt for core 1
	InitialiseTimerChannel(4);

	TimerChannelConfig[4].user_inthandler = UserTimer4Handler;
	SetTimerChannelPeriod(4,100000);

}


void loop1() {
  // put your main code for core 1 here, to run repeatedly:


}



/*** Core 2 ***/

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have no initial values here e.g. uint32 CPU2_var; */
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have an initial value here e.g. uint32 CPU2_var_init = 1; */
EndOfInitialised_CPU2_Variables


void setup2() {
  // put your setup code for core 2 here, to run once:


}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:


}



