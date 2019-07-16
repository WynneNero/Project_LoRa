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

// SerialClass3 SerialASC;  /* Arduino FDTI */
// SerialClass2 Serial1; 	/* RXD1/TXD1 	*/
// SerialClass1 Serial0; 	/* RXD0/TXD0 	*/
// SerialClassRxTx Serial; 	/* RX/TX 	 	*/

uint32 volatile val;
uint32 i;

/* Make sure TX is connected to RX (D1 to D0) 	  */
/* Make sure TX0 is connected to RX0 (D14 to D15) */
/* Make sure TX1 is connected to RX1 (D16 to D17) */

/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(921600); // Fast!

}


void loop() {
// put your main code for core 0 here, to run repeatedly:

	if (Serial.available() > 0)
	{
		val = Serial.read();
		SerialASC.print("Serial  Rx/Tx:    ");SerialASC.println(val,DEC);
	}

	if (Serial0.available() > 0)
	{
		val = Serial0.read();
		SerialASC.print("Serial0 RxD0/TxD0:");SerialASC.println(val,DEC);
	}

	if (Serial1.available() > 0)
	{
		val = Serial1.read();
		SerialASC.print("Serial1 RxD1/TxD1:");SerialASC.println(val,DEC);
	}

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

	delay(500);
	Serial.begin(31250);
	Serial0.begin(31250);
	Serial1.begin(31250);

}


void loop1() {
// put your main code for core 1 here, to run repeatedly:

	int j;

	//for(i = 0 ; i < 255/3 ; i++)
	{

		if(Serial.available() == 0)
		{
			/* Serial (Tx/Rx)*/
			for(j = 0 ; j < 32; j++)
			{
				Serial.write(1);
			}
		}

		if(Serial0.available() == 0)
		{
			for(j = 0 ; j < 32; j++)
			{
				Serial0.write(1);
			}
		}

		if(Serial1.available() == 0)
		{
			for(j = 0 ; j < 32; j++)
			{
				Serial1.write(1);
			}
		}

		//delay(50);
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

	delay(500);


}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:


}



