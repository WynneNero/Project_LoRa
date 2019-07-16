
/* Allow use of VT100 escape sequences */
#include "vt100.h"
#include "arduino.h"

sint8 const Hell[] = "Hello";

/* Simple Board Test Sketch */

char rxdata;

void setup() {
	// put your setup code here, to run once:

	SerialASC.begin(9600);

	SerialASC.print(VT100_CURSOR_OFF);
	SerialASC.print(VT100_CLR_SCREEN);


	SerialASC.print("Test ShieldBuddyTC275 RevC\n\r");
	SerialASC.print("SW Version: ");
	SerialASC.print(F(ShieldBuddyVersion)); SerialASC.print(" Date: "); SerialASC.print(F(ShieldBuddyDate)); SerialASC.print("\n\r");

	SerialASC.print("\n\rPress any key to \n\rproceed with test...");

	rxdata = char(SerialASC.read());
	SerialASC.print("\n\rReceived: ");
	SerialASC.print(rxdata);

	SerialASC.print("\n\r\n\rLED will now flash...");

	// Enable the LED pin
	pinMode(13, OUTPUT);

}


void loop()
{
	// put your main code here, to run repeatedly:

	// Flash the LED

    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(13,HIGH);

}




void setup1()
{



}


void loop1()
{




}


void setup2()
{



}


void loop2()
{




}





