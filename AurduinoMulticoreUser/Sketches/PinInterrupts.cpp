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

uint32 volatile PinIntFunc0_var = 0;
uint32 volatile PinIntFunc21_var = 0;
uint32 volatile PinIntFunc42_var = 0;
uint32 volatile PinIntFunc20_var = 0;
uint32 volatile PinIntFunc23_var = 0;
uint32 volatile PinIntFunc15_var = 0;
uint32 volatile PinIntFunc52_var = 0;
uint32 volatile PinIntFunc13_var = 0;
uint32 volatile PinIntFunc11_var = 0;
uint32 volatile PinIntFunc2_var = 0;
uint32 volatile PinIntFunc33_var = 0;
uint32 volatile PinIntFunc3_var = 0;
uint32 volatile PinIntFunc18_var = 0;


/* Functions called from pin interrupts */
void PinIntFunc18(void)
{

	PinIntFunc18_var++;

}

void PinIntFunc21(void)
{

	PinIntFunc21_var++;

}
void PinIntFunc42(void)
{

	PinIntFunc42_var++;

}
void PinIntFunc20(void)
{

	PinIntFunc20_var++;

}
void PinIntFunc23(void)
{

	PinIntFunc23_var++;

}
void PinIntFunc15(void)
{

	PinIntFunc15_var++;

}
void PinIntFunc52(void)
{

	PinIntFunc52_var++;

}
void PinIntFunc13(void)
{

	PinIntFunc13_var++;

}
void PinIntFunc11(void)
{

	PinIntFunc11_var++;

}

void PinIntFunc2(void)
{

	PinIntFunc2_var++;

}

void PinIntFunc33(void)
{

	PinIntFunc33_var++;

}


void PinIntFunc3(void)
{

	PinIntFunc3_var++;

}

/* Define which pin transition to test */
#define PIN_TRANSITION  RISING
//#define PIN_TRANSITION  FALLING
//#define PIN_TRANSITION  CHANGE

/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	attachInterrupt(18, PinIntFunc18, PIN_TRANSITION);  // Or 42
	attachInterrupt(15, PinIntFunc15, PIN_TRANSITION);
	attachInterrupt(2, PinIntFunc2, PIN_TRANSITION);   // Or 13 or 33
	attachInterrupt(3, PinIntFunc3, PIN_TRANSITION);   // OR 11 or 23
	attachInterrupt(52, PinIntFunc52, PIN_TRANSITION);
	attachInterrupt(20, PinIntFunc20, PIN_TRANSITION);

	pinMode(1, OUTPUT);

}


uint32 volatile delaycounter;

void loop() {
  // put your main code for core 0 here, to run repeatedly:

	/* Generate a square wave to trigger pin interrupts */
	digitalWrite(1,HIGH);

	for(delaycounter = 0 ; delaycounter < 50000; delaycounter++)
	{  }

	digitalWrite(1,LOW);

	for(delaycounter = 0 ; delaycounter < 50000; delaycounter++)
	{ }

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


	/* Deliberately stop pin 20 interrupt after 5 seconds! */
	while(millis() < 5000u) { ; }

	/* Stop pin 20 interrupt */
	detachInterrupt(20);

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

