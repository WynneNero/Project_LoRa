/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */

volatile uint8 Port00_Sample = 0;
uint32 volatile PinIntFunc2_var = 0;

void ReadPort00(void);
void PinIntFunc2(void);


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	/* Call a function every 100us */
	CreateTimerInterrupt(ContinuousTimerInterrupt, 10000, ReadPort00);

	/* Any change on Pin D2 will call the PinIntFunc2 function */
	attachInterrupt(2, PinIntFunc2, CHANGE);
}


void loop() {
  // put your main code for core 0 here, to run repeatedly:


}


/* Entered when pin D2 changes state */
void PinIntFunc2(void)
{

	PinIntFunc2_var++;

}

/* Entered every 100us */
void ReadPort00(void)
{

	/* Read directly Port00 bit 0 to 7.  This is J406 PIN25 to PIN39 */
	Port00_Sample = (uint8)P00_IN.U;

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



