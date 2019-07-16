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

int volatile ADresult[16]; /* n is an array of 10 integers */
int volatile i,j;



/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:
  //
  SerialASC.begin(9600);

  analogReadResolution(12);
  //
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);    // onboard LED

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:
  //
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  //
  delay(100); // wait for a 1/10 second.
  SerialASC.print("Testing analog in\n\r");
  delay(100); // wait for a 1/10 second.
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  //
  //                           // Aansluitngen AD7..0 verwisseld in documentatie ... vermelding op board klopt
  ADresult[0]=ReadAD0();       // Als niks aangesloten dan ongeveer 520 als waarde 5volt = 1023/1024
  ADresult[1]=ReadAD1();
  ADresult[2]=ReadAD2();
  ADresult[3]=ReadAD3();
  //
  SerialASC.print("#A0");
  for (j = 0; j <= 3; j++ ) {
     //
     SerialASC.print(":");  
     SerialASC.print(ADresult[j],DEC);
     // 
   }
  SerialASC.print("\n\r");
  //
  //
  //                           // Aansluitngen AD7..0 verwisseld in documentatie ... vermelding op board klopt
  ADresult[4]=ReadAD4();       // Als niks aangesloten dan ongeveer 520 als waarde 5volt = 1023/1024
  ADresult[5]=ReadAD5();
  ADresult[6]=ReadAD6();
  ADresult[7]=ReadAD7();
  //
  SerialASC.print("#A4");
  for (j = 4; j <= 7; j++ ) {
     // 
     SerialASC.print(":");  
     SerialASC.print(ADresult[j],DEC);
     // 
   }
  SerialASC.print("\n\r");
  //
  //
  //                           // Aansluitngen AD7..0 verwisseld in documentatie ... vermelding op board klopt
  ADresult[8]=ReadAD8();       // Als niks aangesloten dan ongeveer 520 als waarde 5volt = 1023/1024
  ADresult[9]=ReadAD9();
  ADresult[10]=ReadAD10();
  ADresult[11]=ReadAD11();
  //
  SerialASC.print("#A8");
  for (j = 8; j <= 11; j++ ) {
     // 
     SerialASC.print(":");  
     SerialASC.print(ADresult[j],DEC);
     // 
   }
  SerialASC.print("\n\r");
  //
  //
  //                             // ReadAD12 .. ReadAD15 geeft foutmelding ReadADxx was not declared in this scope.
  ADresult[12]=ReadAD12();     // Als niks aangesloten dan ongeveer 520 als waarde 5volt = 1023/1024
  ADresult[13]=ReadAD13();
  ADresult[14]=ReadAD14();
  ADresult[15]=ReadAD15();
  //
  SerialASC.print("#A12");
  for (j = 12; j <= 15; j++ ) {
     // 
     SerialASC.print(":");  
     SerialASC.print(ADresult[j],DEC);
     // 
     }
  SerialASC.print("\n\r");    
  //  
  //
  delay(1000); // wait for a 1 second.
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


