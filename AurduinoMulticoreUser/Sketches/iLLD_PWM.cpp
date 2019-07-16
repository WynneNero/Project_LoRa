/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

#include "ccu6pwmbcdemo.h"
#include "vt100.h"

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */




/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

	/* Assume that a VT100-compatible terminal is being used */
	SerialASC.print(VT100_CURSOR_OFF);
	SerialASC.print(VT100_CLR_SCREEN);

	/* Initialise CCU for 3phase brushless drives */
	Ccu6PwmBcDemo_init();

	/* Start the 3phase brushless driver */
    IfxCcu6_PwmBc_start(&g_Ccu6PwmBc.drivers.pwmBc);

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


}


void loop1() {
  // put your main code for core 1 here, to run repeatedly:

	SerialASC.print(VT100_CURSOR_HOME);
	SerialASC.print("T12 Frequency = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t12Frequency);SerialASC.print("Hz\n\r");
	SerialASC.print("T13 Frequency = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t13Frequency);SerialASC.print("Hz\n\r");
	SerialASC.print("T13 Period    = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t12Period);SerialASC.print("\n\r");
	SerialASC.print("T13 Period    = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.base.t13Period);SerialASC.print("\n\r");

	SerialASC.print("Hall pattern  = "); SerialASC.print(g_Ccu6PwmBc.drivers.pwmBc.hallPatternIndex);SerialASC.print("\n\r");
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



