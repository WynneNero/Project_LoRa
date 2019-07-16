/*
 * EEPROM Write
 *
 * Stores values read from analog input 0 into the EEPROM.
 * These values will stay in the EEPROM when the board is
 * turned off and may be retrieved later by another sketch.
 */

#include <EEPROM.h>

//#pragma GCC optimize "-O0"

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
uint32 addr = 0;
uint8 val;
uint32 i;
uint32 EEPROM_TestCounter = 0;
uint32 DataShift = 0;

void setup() {
  /** Empty setup. **/

    /* Deliberately create a bad sector */
    //DFlash_Erase(0xAF000000,4);

	/* Erase entire DFLASH */
    //EEPROM.eeprom_erase();

	/* Corrupt CRC in sector 2 */
    //CreateCrcError(4);  /* Should stop after next line */

    /* Initialise EEPROM system */
	if(EEPROM.eeprom_initialise() == EEPROM_Not_Initialised)
	{
		// EEPROM is bad
		while(1) { ; }
	}

	EEPROM_TestCounter = 0;
}

void loop() {

	/* Write some data to EEPROM (buffer) */
	for(addr = 0 ; addr < EEPROM.length(); addr++)
	{

		val = (addr & 0xFF) ^ DataShift;  // EXOR make sure data is not the same in all sectors
		EEPROM.write(addr, val);

	}

	/* Write buffer to DFLASH */
    EEPROM.eeprom_update();

    /* Read back data to see if it has changed */
    for(addr = 0; addr < EEPROM.length(); addr++)
    {
    	val = (addr & 0xFF) ^ DataShift;
    	if(val != EEPROM.read(addr))
    	{
    		while(1){ ; } // Bad read - wait in loop
    	}
    }

    /* A source of non-volatile data */
    DataShift = ValidSectorNo;

    EEPROM_TestCounter++;

    /* Start again after each sector is used */
    Reset_TC275();

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




