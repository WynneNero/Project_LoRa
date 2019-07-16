/* Include */
#include "arduino.h"
#include "TinyGPS++.h"

TinyGPSPlus dataGPS;

char GPS_DATA, data;
int cpt=0;
double latitude;
double longitude;
double altitude;
double vitesse;
unsigned long nbre_sat;
int a,b,c;

short conv_alt=0;
float conv_longi=0;
float conv_lati=0;

char byte_received;

char tab[50];

uint8_t prefix = 0x3E;

typedef struct {
       /*
       mtype_id_t  mtype_id;
       crc_wtype_t crc_wtype;
       head_gpse_t head_gpserr;
       */
       uint8_t     mtype   : 4,    //
                   id      : 4,    // no tiiklaa esoshu ID atshkjiriigs ID,
                                   // ko gjeneree peec 0 slota noklausiishanaas
                   crcl    : 8,    //
                   wtype   : 4,    //+2
                   crch    : 4,    //
                   avSNR   : 8,    //
                   headl   : 8,    //
                   headh   : 4,    //
                   gpserr  : 4;    //
       short    alt;            //
       float    lat;            //
       float    lon;            //
       //TStamp_t    stamp;
       uint8_t     tstamp[2];      //kad sanjemts peedeejais GPS, info no hosta
   }  __attribute__((packed)) gps_struct_t;

void send_struct_to_serial (uint8_t size, void * GPS)
{
	uint8_t * iter = (uint8_t *) GPS;
	for (int i=0;  i < size; i++)
	{
		Serial.write(*iter);
		iter++;
	}
}

void send_struct_to_LoRa_Serial1 (uint8_t prefix, uint8_t size, void * GPS)
{
	Serial1.write(prefix);
	Serial1.write(size);
	uint8_t * iter = (uint8_t *) GPS;

	for (int i=0;  i < size; i++)
	{
		Serial1.write(*iter);
		iter++;
	}

}

void filled_array (uint8_t size)
{

	while (Serial0.available())
			  {

	     	   for(int i=0 ;i<size ;i++)
	     	   {
	     		  byte_received = Serial0.read();
	     		  SerialASC.write(byte_received);
	     		  tab[i]=byte_received;
	     	   }
	     	   cpt++;
			  }





}

void filled_struct ()
{

}

uint8_t struct_size = sizeof(gps_struct_t);


void setup()
{

	Serial.begin(9600);

}


void loop()
{
/*

	////////////////////////////GPS///////////////////////////////////////////////////////////////
	while (Serial0.available())
		  {
		   GPS_DATA = Serial0.read();
	       dataGPS.encode(GPS_DATA);
	       if (dataGPS.location.isUpdated())
	         {
	    	   latitude = dataGPS.location.lat();
	    	   longitude = dataGPS.location.lng();
	    	   altitude = dataGPS.altitude.meters();

	    	   vitesse = dataGPS.speed.kmph();
	    	   nbre_sat = dataGPS.satellites.value();

	    	   	SerialASC.println("-------- FIX GPS ------------");
	    	   	SerialASC.print("LATITUDE="); SerialASC.println(latitude);
	    	    SerialASC.print("LONGITUDE="); SerialASC.println(longitude);
	    	   	SerialASC.print("ALTITUDE (m) ="); SerialASC.println(altitude);
	    	   	SerialASC.print("VITESSE (km/h)="); SerialASC.println(vitesse);
	    	   	SerialASC.print("NOMBRE SATTELLITES="); SerialASC.println(nbre_sat);

	          }

	       conv_alt=(short)altitude;
	       conv_longi=(float)longitude;
	       conv_lati=(float)latitude;

	       a = sizeof(conv_alt);
	       b = sizeof(conv_longi);
	       c = sizeof(conv_lati);
		  }
*/

	 gps_struct_t message = {15,15,255,15,15,255,255,15,15,conv_alt,conv_lati,conv_longi,15,127};
	 uint8_t struct_size = sizeof(gps_struct_t);
	 send_struct_to_serial (struct_size, &message);
	 //send_struct_to_LoRa_Serial1(prefix, struct_size, &message);
}


void setup1()
{


	Serial0.begin(9600);
	SerialASC.begin(9600);


}


void loop1()
{

	filled_array (struct_size);


}


void setup2()
{


}


void loop2()
{




}
