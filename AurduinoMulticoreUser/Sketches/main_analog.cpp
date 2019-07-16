/*
 * main_analog.c
 *
 *  Created on: 8 Apr 2015
 *      Author: smccumiskey
 */

uint8 period;

void setup(){
	SerialASC.begin(9600);
	SerialASC.println("\nGreetings!");
	SerialASC.print("Type in your desired duty ratio(0/256): ");
	analogWrite(3,256);
	pinMode(12,OUTPUT);
	pinMode(9,OUTPUT);
	digitalWrite(12,HIGH);
	digitalWrite(9,LOW);
}

void loop(){
	char num;
	if(SerialASC.available() > 0){
		num = SerialASC.read();
		SerialASC.print(num);
		if(num == '\n' || num == '\r'){
			period = period < 255 ? period : 255;
			period = period > 0 ? period : 0;
			analogWrite(3,period);
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

