
/* Allow use of VT100 escape sequences */
#include "vt100.h"

uint16 volatile VADC_result[NoOfVadcChannels];


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	analogReadResolution(8);

	SerialASC.begin(9600);

	SerialASC.print(VT100_CURSOR_OFF);
	SerialASC.print(VT100_CLR_SCREEN);

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:

	int i;

	SerialASC.print(VT100_CURSOR_HOME);

	for(i = 0 ; i < NoOfVadcChannels; i++)
	{

		VADC_result[i] = analogRead(i);

	}

	for(i = 0 ; i < NoOfVadcChannels; i++)
	{

		SerialASC.print("\n\rAD");SerialASC.print(i);SerialASC.print(" = ");SerialASC.print(VADC_result[i]);SerialASC.print("       ");
	}
}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:

}

void loop1() {
  // put your main code core 1 here, to run repeatedly:

}



/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:


}

void loop2() {
  // put your main code core 2 here, to run repeatedly:

}






