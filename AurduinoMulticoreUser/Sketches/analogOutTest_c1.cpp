/*
 * main_analog.c
 *
 *  Created on: 8 Apr 2015
 *      Author: smccumiskey
 */

uint8 period;

void setup()
{



}

int PinState = 0;

void loop()
{


}

void setup1()
{

	int i;

	SerialASC.begin(9600);
	SerialASC.println("\nGreetings!");
	SerialASC.print("Type in your desired duty ratio(0/256): ");

	for(i = 0 ; i < 13 ; i++)
	{
		analogWrite(i,256);
	}

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

	analogWrite(3, 128);
	analogWrite(4, 128);
	analogWrite(5, 128);
	analogWrite(6, 128);
	analogWrite(7, 128);
	analogWrite(8, 128);
	analogWrite(9, 128);
	analogWrite(10, 128);
	analogWrite(11, 128);
	analogWrite(12, 128);

}


void loop1()
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


void setup2()
{



}


void loop2()
{




}

