

/* Allow use of VT100 escape sequences */
#include "vt100.h"

typedef enum { StopCore, StartCore } CoreControlType;


/* CPU0 Uninitialised Data */
StartOfUninitialised_CPU0_Variables
uint32 volatile CPU0_var;
uint32 volatile CPU0_var1;
uint32 volatile CPU0_var2;
EndOfUninitialised_CPU0_Variables

/* CPU0 Initialised Data */
StartOfInitialised_CPU0_Variables
uint32 volatile CPU0_var_init = 1;
CoreControlType volatile Core0Control = StopCore;
EndOfInitialised_CPU0_Variables

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
uint32 volatile CPU1_var;
uint32 volatile CPU1_var1;
uint32 volatile CPU1_var2;
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
uint32 volatile CPU1_var_init = 1;
CoreControlType volatile Core1Control = StopCore;
unsigned int CPU1_time1 = 0;
unsigned int CPU1_time2 = 0;
unsigned int CPU1_millis = 0;
unsigned int CPU1_time3 = 0;
EndOfInitialised_CPU1_Variables

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
uint32 volatile CPU2_var;
uint32 volatile CPU2_var1;
uint32 volatile CPU2_var2;
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
uint32 volatile CPU2_var_init = 1;
CoreControlType volatile Core2Control = StopCore;
unsigned int CPU2_time1 = 0;
unsigned int CPU2_time2 = 0;
unsigned int CPU2_millis = 0;
unsigned int CPU2_time3 = 0;
EndOfInitialised_CPU2_Variables

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
uint32 volatile LMU_var;
uint32 volatile CPU2_LMU_var;
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
uint32 volatile LMU_var_init = 1;
EndOfInitialised_LMURam_Variables

/* These globals will be in the CPU0 DSPR RAM */
unsigned int CPU0_time1 = 0;
unsigned int CPU0_time2 = 0;
unsigned int CPU0_millis = 0;
unsigned int CPU0_time3 = 0;

#define NOOFLOOPS   0x1000000



/*** Core 0 ***/
/* Lockstep, efficiency core */

void setup() {
  // put your setup code for core 0 here, to run once:

	Core1Control = StopCore;
	Core2Control = StopCore;
	Core0Control = StartCore;

	SerialASC.begin(9600);

	SerialASC.print(VT100_CURSOR_OFF);
	SerialASC.print(VT100_CLR_SCREEN);

}




void loop() {
  // put your main code for core 0 here, to run repeatedly:

	unsigned int i;

	while(Core0Control == StopCore)
	{ ; }

	CPU0_time1 = millis();

	for(i = 0 ; i < NOOFLOOPS; i++)
	{

		CPU0_var = i; // 251ms

	}

	CPU0_millis = millis();

	CPU0_time2 = CPU0_millis - CPU0_time1;

	for(i = 0 ; i < NOOFLOOPS; i++)
	{

		CPU1_var = i; // 671ms

	}

	CPU0_time3 = millis() - CPU0_millis;

	SerialASC.print(VT100_CURSOR_HOME);

	//SerialASC.print("CPU0 Time 1 "); SerialASC.print(CPU0_time1);SerialASC.print("\n\r");
	SerialASC.print("CPU0 Time 2 "); SerialASC.print(CPU0_time2);SerialASC.print("    \n\r");
	SerialASC.print("CPU0 Time 3 "); SerialASC.print(CPU0_time3);SerialASC.print("    \n\r");
	//SerialASC.print("CPU1 Time 1 "); SerialASC.print(CPU1_time1);SerialASC.print("    \n\r");
	SerialASC.print("CPU1 Time 2 "); SerialASC.print(CPU1_time2);SerialASC.print("    \n\r");
	SerialASC.print("CPU1 Time 3 "); SerialASC.print(CPU1_time3);SerialASC.print("    \n\r");
	//SerialASC.print("CPU2 Time 1 "); SerialASC.print(CPU2_time1);SerialASC.print("\n\r");
	SerialASC.print("CPU2 Time 2 "); SerialASC.print(CPU2_time2);SerialASC.print("    \n\r");
	SerialASC.print("CPU2 Time 3 "); SerialASC.print(CPU2_time3);SerialASC.print("    \n\r");

	// Stop core 0
	// Start core 1 again
	// This is to make sure that the SRI is not being hit by all 3 cores at once.
	Core0Control = StopCore;
	Core1Control = StartCore;

}


/*** Core 1 ***/
/* Lockstep, performance core */
void setup1() {
  // put your setup code for core 1 here, to run once:

	Core1Control = StopCore;


}


void loop1() {
  // put your main code core 1 here, to run repeatedly:

	unsigned int i;

	while(Core1Control == StopCore)
	{ ; }

	CPU1_time1 = millis();

	for(i = 0 ; i < NOOFLOOPS; i++)
	{

		CPU1_var1 = i;  // 168ms

	}

	CPU1_millis = millis();

	CPU1_time2 = CPU1_millis - CPU1_time1;

	for(i = 0 ; i < NOOFLOOPS; i++)
	{

		CPU0_var1 = i; // 2180ms

	}

	CPU1_time3 = millis() - CPU1_millis;

	// Stop core 1
	// Start core 2
	Core1Control = StopCore;
	Core2Control = StartCore;

}


/*** Core 2 ***/
/* Non-Lockstep, performance core */
void setup2() {
  // put your setup code for core 2 here, to run once:

	Core2Control = StopCore;

}


void loop2() {
  // put your main code core 2 here, to run repeatedly:

	unsigned int i;

	while(Core2Control == StopCore)
	{ ; }

	CPU2_time1 = millis();

	for(i = 0 ; i < NOOFLOOPS; i++)
	{

		//CPU2_var = i; // 2179ms
		CPU0_var2 = i; // 2180ms

	}

	CPU2_millis = millis();

	CPU2_time2 = CPU2_millis - CPU2_time1;

	for(i = 0 ; i < NOOFLOOPS; i++)
	{

		//CPU0_var2 = i; // 671ms
		CPU2_var = i; // 168ms

	}

	CPU2_time3 = millis() - CPU2_millis;

	// Stop core 2
	// Start core 0 again
	Core2Control = StopCore;
	Core0Control = StartCore;

}



