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


#define ARDUINO_IO   0


uint8 IOcontrol = ARDUINO_IO ;


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);

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


uint32 PinRecorder[256];
uint8 PinRecorderIdx = 0;

void loop1() {
  // put your main code for core 1 here, to run repeatedly:

	while(1)
	{
		PinRecorder[PinRecorderIdx++] = Fast_digitalRead(D2);
	}

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

	if(IOcontrol == ARDUINO_IO)
	{
	// Arduino-style pin control
	digitalWrite(2,HIGH);  // 160n, 6.25MHz core 0/1/2
	digitalWrite(2,LOW);   // 120ns core1/2
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(2,HIGH);
	digitalWrite(2,LOW);
	}
	else
	{
	// ShieldBuddy-style pin control
	Fast_digitalWrite(D2, LOW);  // 100ns, 10MHz Core1/2
	Fast_digitalWrite(D2, HIGH); // 130ns, core0
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);
	Fast_digitalWrite(D2, LOW);
	Fast_digitalWrite(D2, HIGH);

	}


}




