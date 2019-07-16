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

#define NO_OF_ADC_SAMPLES  512

#define Test_ADC_Res  10

uint16 volatile ADresult[NO_OF_ADC_SAMPLES]; /* n is an array of 10 integers */
int volatile i,j;

uint16 volatile MaxVal;
uint16 volatile MinVal;

uint16 volatile Max_MaxVal;
uint16 volatile Min_MinVal;
uint8 volatile STCS_val = 0;

typedef struct { uint8 STCS;
				 uint16 Range; } RangeResultsType;

RangeResultsType RangeResults[0x20];

/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:
  //

	uint8 i;

	SerialASC.begin(1000000);

	analogReadResolution(Test_ADC_Res);
	//
	// initialize digital pin 13 as an output.
	pinMode(13, OUTPUT);    // onboard LED
	//

	delay(100); // wait for a 1/10 second.
	//SerialASC.print("Testing analog in A0\n\r");
    delay(100); // wait for a 1/10 second.

    IfxPort_setPinMode(&MODULE_P40, 9, IfxPort_Mode_inputNoPullDevice);   // AD0 SAR4.7 / P40.9


    Min_MinVal = 0xFFFF;
	Max_MaxVal = 0;

}




void loop() {
  // put your main code for core 0 here, to run repeatedly:

  for(j = 0 ; j < 0x20; j++)
  {

	  // Chang sample time for next pass
	  VADC_G4ICLASS0.U = (VADC_10BitConversion << 8) |(STCS_val & 0x1F) ;

	  for(i = 0 ; i < NO_OF_ADC_SAMPLES; i++)
	  {

		  ADresult[i] = ReadAD0();     // Read AD0

	  }

	  MinVal = 0xFFFF;
	  MaxVal = 0;

	  for(i = 0 ; i < NO_OF_ADC_SAMPLES; i++)
	  {

		  if(MaxVal < ADresult[i])
		  {

			  MaxVal = ADresult[i];

		  }

		  if(MinVal > ADresult[i])
		  {

			  MinVal = ADresult[i];

		  }

	  }

	  RangeResults[j].Range = MaxVal - MinVal;
	  RangeResults[j].STCS = j;

  }
  //

  if(MaxVal > Max_MaxVal)
  {

	  Max_MaxVal = MaxVal;

  }

  if(MinVal < Min_MinVal)
  {

	  Min_MinVal = MinVal;

  }


  for (j = 0; j < NO_OF_ADC_SAMPLES; j++ ) {

	  SerialASC.print(Max_MaxVal,DEC);SerialASC.print(" ");
	  SerialASC.print(ADresult[j],DEC);SerialASC.print(" ");SerialASC.print(MaxVal,DEC);SerialASC.print(" ");SerialASC.println(MinVal,DEC);

  }


  for (j = 0; j < 0x20; j++ ) {
     //

	  //SerialASC.print(RangeResults[j].Range,DEC); SerialASC.print(" "); SerialASC.println(RangeResults[j].STCS,DEC);
	  //SerialASC.print("Range:"); SerialASC.print(RangeResults[j].Range,DEC);
	  //SerialASC.print(" STCS: "); SerialASC.println(RangeResults[j].STCS,DEC);

     // 
   }
 // SerialASC.print("\n\r");

  //
  
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



