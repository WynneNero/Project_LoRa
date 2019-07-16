/* Include */
#include "arduino.h"
#include "TinyGPS++.h"

////////////////////////////INCLUDE GPS TEST////////////////////////////////////////////////////////////////

//sint8 const Hell[] = "Hello";

/* Simple Board Test Sketch */


char data;
double latitude;
double longitude;
double altitude; //altitude
double vitesse;
unsigned long nbre_sat;

short conv_alt=0;
float conv_lati=0;
float conv_longi=0;

char initATZ[4]={0x41,0x54,0x5A};
char initAT0[4]={0x41,0x54,0x30};
char initQ0[3]={0x51,0x30};

int cpt=0, cpt1=0;

uint8_t prefix = 0x3E;

TinyGPSPlus gps;

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


void send_struct_to_LoRa_Serial0 (uint8_t prefix, uint8_t size, void * GPS)
{
	Serial0.write(prefix);
	Serial0.write(size);
	uint8_t * iter = (uint8_t *) GPS;

	for (int i=0;  i < size; i++)
	{
		Serial0.write(*iter);
		iter++;
	}

}


void setup() {
	// put your setup code here, to run once:



	////////////////////////////GPS TEST////////////////////////////////////////////////////////////////


	  //Initialize serial and wait for port to open:
	  Serial.begin(9600);
	  SerialASC.begin(9600);
	  Serial0.begin(115200);
	  delay(10000);
	  Serial0.write(initATZ);
	  Serial0.flush();
	  delay(2000);
	  Serial0.write(initAT0);
	  Serial0.flush();
	  delay(2000);
	  Serial0.write(initQ0);
	  Serial0.flush();




}


void loop()
{
	// put your main code here, to run repeatedly:




	////////////////////////////GPS TEST////////////////////////////////////////////////////////////////

	while (Serial.available()) {
	    data = Serial.read();
	    gps.encode(data);
	    if (gps.location.isUpdated())
	    {
	      latitude = gps.location.lat();
	      longitude = gps.location.lng();
	      altitude = gps.altitude.meters();
	      vitesse = gps.speed.kmph();
	      nbre_sat = gps.satellites.value();


	    }
	       conv_alt=(short)altitude;
	       conv_longi=(float)longitude;
	       conv_lati=(float)latitude;
	    cpt++;
	  }
			SerialASC.println("-------- FIX GPS ------------");
	      SerialASC.print("LATITUDE="); SerialASC.println(latitude);
	      SerialASC.print("LONGITUDE="); SerialASC.println(longitude);
	      SerialASC.print("ALTITUDE (m) ="); SerialASC.println(altitude);
	      SerialASC.print("VITESSE (km/h)="); SerialASC.println(vitesse);
	      SerialASC.print("NOMBRE SATTELLITES="); SerialASC.println(nbre_sat);
	      cpt1++;


	      gps_struct_t message = {15,15,255,15,15,255,255,15,15,conv_alt,conv_lati,conv_longi,15,127};
	      	uint8_t struct_size = sizeof(gps_struct_t);
	      	cpt1++;
	      	send_struct_to_LoRa_Serial0(prefix, struct_size, &message);

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



