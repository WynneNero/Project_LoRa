#include "arduino.h"

int Core0Done = 0;
int Core1Done = 0;

/*** Core 0 ***/

void setup() {
  SerialASC.begin(115200);           // set up Serial library at 115.200 bps
  int startTime=micros();
  int startTime2=millis();
  delay(10);
  int delta=micros()-startTime;
  int delta2=millis()-startTime2;
  SerialASC.print("Core 0 delay(10) measured with micros(): "); SerialASC.println(delta);
  SerialASC.print("Core 0 delay(10) measured with millis() "); SerialASC.println(delta2);

  startTime=micros();
  startTime2=millis();
  delayMicroseconds(10000);
  delta=micros()-startTime;
  delta2=millis()-startTime2;
  SerialASC.print("Core 0 delayMicroseconds(10000) measured with micros(): "); SerialASC.println(delta);
  SerialASC.print("Core 0 delayMicroseconds(10000) measured with millis() "); SerialASC.println(delta2);

  pinMode(30,OUTPUT);

  Core0Done = 1;

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:

	digitalWrite(30,HIGH);
	delay(1);
	//delayMicroseconds(1000);
	digitalWrite(30,LOW);
	delay(1);
	//delayMicroseconds(1000);

}


/*** Core 1 ***/
void setup1() {



}


void loop1() {
  // put your main code core 1 here, to run repeatedly:


}



/*** Core 2 ***/
void setup2() {

}


void loop2() {
  // put your main code core 2 here, to run repeatedly:

}

