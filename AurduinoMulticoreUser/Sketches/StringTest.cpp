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

/*
    String constructors

  Examples of how  to create strings from other data types

  created 27 July 2010
  modified 30 Aug 2011
  by Tom Igoe

  http://www.arduino.cc/en/Tutorial/StringConstructors

  This example code is in the public domain.
  */


void setup() {


   // Open serial communications and wait for port to open:
   SerialASC.begin(9600);
   while (!Serial) {
     ; // wait for serial port to connect. Needed for native USB port only
   }

   // send an intro:
   SerialASC.println("\n\nString Constructors:");
   SerialASC.println();
}

void loop() {
   // using a constant String:
   String stringOne = "Hello String";
   SerialASC.println(stringOne);      // prints "Hello String"

   // converting a constant char into a String:
   stringOne =  String('a');
   SerialASC.println(stringOne);       // prints "a"

   // converting a constant string into a String object:
   String stringTwo =  String("This is a string");
   SerialASC.println(stringTwo);      // prints "This is a string"

   // concatenating two strings:
   stringOne =  String(stringTwo + " with more");
   // prints "This is a string with more":
   SerialASC.println(stringOne);

   // using a constant integer:
   stringOne =  String(13);
   SerialASC.println(stringOne);      // prints "13"

   // using an int and a base:
   stringOne =  String(analogRead(A0), DEC);
   // prints "453" or whatever the value of analogRead(A0) is
   SerialASC.println(stringOne);

   // using an int and a base (hexadecimal):
   stringOne =  String(45, HEX);
   // prints "2d", which is the hexadecimal version of decimal 45:
   SerialASC.println(stringOne);

   // using an int and a base (binary)
   stringOne =  String(255, BIN);
   // prints "11111111" which is the binary value of 255
   SerialASC.println(stringOne);

   // using a long and a base:
   stringOne =  String(millis(), DEC);
   // prints "123456" or whatever the value of millis() is:
   SerialASC.println(stringOne);

   //using a float and the right decimal places:
   stringOne = String(5.698, 3);
   SerialASC.println(stringOne);

   //using a float and less decimal places to use rounding:
   stringOne = String(5.698, 2);
   SerialASC.println(stringOne);

   // do nothing while true:
   while (true);

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



