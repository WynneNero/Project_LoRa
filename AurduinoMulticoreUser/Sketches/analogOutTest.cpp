/*
 * main_analog.c
 *
 *  Created on: 8 Apr 2015
 *      Author: smccumiskey
 */
#include "Arduino.h"
#include "analogOut.h"



/* Global Variable */
uint8 period;
int PinState = 0;



void setup()
{
	uint32 i;

	/* Configuring the digital IO */
	pinMode(12,OUTPUT);
	pinMode(9,OUTPUT);
	digitalWrite(12,HIGH);
	digitalWrite(9,LOW);

	pinMode(30,OUTPUT);
	pinMode(31,OUTPUT);
	pinMode(40,OUTPUT);
	pinMode(48,OUTPUT);

	digitalWrite(30,HIGH);
	digitalWrite(31,HIGH);
	digitalWrite(40,HIGH);
	digitalWrite(48,HIGH);

	/* Use 1.5kHz PWM carrier like Arduino Uno */
	//useArduinoPwmFreq();

	/* Use 4000Hz carrier */
	useCustomPwmFreq(4000);

	/* Configure the serial port */
	SerialASC.begin(9600);
	SerialASC.println("\n\n\n\rGreetings!");

	/* Set All duties to 100% Initially */
	SerialASC.println("\nSetting the duties for PWM2 - PWM13 to 100%\n\r");
	SerialASC.println("Press return key to proceed to next test\n\r");

	for(i = 2 ; i < 13 ; i++)
	{
		analogWrite(i, 256);
	}
	(void) SerialASC.read();

	/* Set Duties to stair case for scope debugging */
	SerialASC.println("\nSetting the duties for PWM2 -PWM13 to a test staircase\n\r");
	SerialASC.println("Press return key to proceed to next test\n\r");

	analogWrite(2,   10);
	analogWrite(3,   20);
	analogWrite(4,   30);
	analogWrite(5,   40);
	analogWrite(6,   50);
	analogWrite(7,   60);
	analogWrite(8,   70);
	analogWrite(9,   80);
	analogWrite(10,  90);
	analogWrite(11, 100);
	analogWrite(12, 110);
	(void) SerialASC.read();

	/* DAC0 & DAC1 - 6.1KHz */
	SerialASC.println("\nSetting the duties for DAC0 & DAC1 to 100% at 6.1kHz\n\r");
	SerialASC.println("Press return key to proceed to next test\n\r");

	analogWrite(100, Resolution14Bit);
	analogWrite(101, Resolution14Bit);
	(void) SerialASC.read();

	/* DAC0 & DAC1 - 6.1KHz */
	SerialASC.println("\nSetting the duties for DAC0 & DAC1 to 50% at 6.1kHz\n\r");
	SerialASC.println("Press return key to proceed to next test\n\r");

	analogWrite(100, Resolution14Bit/2);
	analogWrite(101, Resolution14Bit/2);
	(void) SerialASC.read();


	/* DAC0 & DAC1 - 270KHz & 529KHz */
	SerialASC.println("\nSetting the duties for DAC0 & DAC1 to 100% at 270KHz & 529KHz\n\r");
	SerialASC.println("Press return key to proceed to next test\n\r");

	analogWrite(102, AnalogOutDAC0_RF_270kHzCarrier);
	analogWrite(103, AnalogOutDAC1_RF_529kHzCarrier);
	(void) SerialASC.read();

	/* DAC0 & DAC1 - 270KHz & 529KHz */
	SerialASC.println("\nSetting the duties for DAC0 & DAC1 to 50% at 270KHz & 529KHz\n\r");
	SerialASC.println("Press return key to proceed to next test\n\r");

	analogWrite(102, AnalogOutDAC0_RF_270kHzCarrier/2);
	analogWrite(103, AnalogOutDAC1_RF_529kHzCarrier/2);
	(void) SerialASC.read();


	/* Proceed to loop for duty ratio user entry tests */
	SerialASC.print("\n\rType in your desired duty ratio(0/256): ");
}




void loop()
{
	char num;
	int i;

	if(SerialASC.available() > 0)
	{

		PinState++;

		digitalWrite(30,PinState & 1);
		digitalWrite(31,PinState & 1);
		digitalWrite(40,PinState & 1);
		digitalWrite(48,PinState & 1);

		num = SerialASC.read();
		SerialASC.print(num);
		if(num == '\n' || num == '\r'){
			period = period < 255 ? period : 255;
			period = period > 0 ? period : 0;

			for(i = 0 ; i < 13 ; i++)
			{
				analogWrite(i, period);
			}

			SerialASC.print("\n\rType in your desired duty ratio(0/256): ");
			period = 0;
		}
		else if(isdigit(num)){
			period = period*10 + (num - '0');
		}

	}

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

