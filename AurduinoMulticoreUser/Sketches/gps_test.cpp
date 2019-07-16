/* Include */
#include "arduino.h"
#include "TinyGPS++.h"

////////////////////////////INCLUDE GPS TEST////////////////////////////////////////////////////////////////

//sint8 const Hell[] = "Hello";

/* Simple Board Test Sketch */

int cpt, cpt1;
char data;
double latitude;
double longitude;
double alt; //altitude
double vitesse;
unsigned long nbre_sat;

TinyGPSPlus gps;


void setup() {
	// put your setup code here, to run once:



	////////////////////////////GPS TEST////////////////////////////////////////////////////////////////


	  //Initialize serial and wait for port to open:
	  Serial.begin(9600);
	  SerialASC.begin(9600);




}


void loop()
{
	// put your main code here, to run repeatedly:




	////////////////////////////GPS TEST////////////////////////////////////////////////////////////////

	while (Serial.available()) {
	    data = Serial.read();
	    //SerialASC.print(data);
	    gps.encode(data);
	    if (gps.location.isUpdated())
	    {
	      latitude = gps.location.lat();
	      longitude = gps.location.lng();
	      alt = gps.altitude.meters();
	      vitesse = gps.speed.kmph();
	      nbre_sat = gps.satellites.value();


	    }

	    cpt++;
	  }
			SerialASC.println("-------- FIX GPS ------------");
	      SerialASC.print("LATITUDE="); SerialASC.println(latitude);
	      SerialASC.print("LONGITUDE="); SerialASC.println(longitude);
	      SerialASC.print("ALTITUDE (m) ="); SerialASC.println(alt);
	      SerialASC.print("VITESSE (km/h)="); SerialASC.println(vitesse);
	      SerialASC.print("NOMBRE SATTELLITES="); SerialASC.println(nbre_sat);
	      cpt1++;
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



