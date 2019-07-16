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

/* This example just causes the bootloader to program itself back into PFlash via TFTP.
 *
 * To do this, create a batchfile containing:
 *
 * C:\Hitex\AURduinoIDE\Tools\hex2bin C:\HIGHTEC\AurduinoUpload.hex
 * C:\Hitex\AURduinoIDE\Tools\tftp -i 192.168.3.177 put C:\HIGHTEC\AurduinoUpload.bin
 *
 * There is a ready made one in:
 *
 * C:\Hitex\AURduinoIDE\Tools\SendAppTftp.bat
 *
 * The IP address "192.168.3.177" will need to be changed to suit your local network environment, as will
 * the IP addresses given in .\aurix\system\include\net.h.
 *
 * The LED on the board will flash until the TFTP connection is made at which point it stops.
 * When the programming is completed, the TC275 will be reset and the bootloader will restart.
 *
 * Note that CPU1 & 2 cannot be used during this process.
 *
 * */


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	// Call the bootloader to program itself back into Flash!
	// Ends with a TC275 reset if programming was successful otherwise it returns
	// after 10 seconds.
	EnterBootLoader();

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



