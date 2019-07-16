/* Include */
#include "arduino.h"
#include "TinyGPS++.h"

/* Simple Board Test Sketch */

char data, data2;
int cpt=0;

char initATZ[4]={0x41,0x54,0x5A};
char initAT0[4]={0x41,0x54,0x30};



int i=0;

TinyGPSPlus dataGPS;

double latitude;
double longitude;
double altitude;
double vitesse;
unsigned long nbre_sat;
int a,b,c;

short conv_alt;
float conv_longi;
float conv_lati;



uint8_t prefix = 0x3E;

// sapakot!!!

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




void send_struct_to_serial (uint8_t prefix, uint8_t size, void * GPS)
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


//gps_struct_t message = {15,15,255,15,15,255,255,15,15,(uint16_t)altitude,(uint32_t)latitude,(uint32_t)longitude,255,127};
//serialized_data.gps_data = {15,15,255,15,15,255,255,15,15,(uint16_t)altitude,(uint32_t)latitude,(uint32_t)longitude,255};

uint8_t struct_size = sizeof(gps_struct_t);



void setup()
{
	// put your setup code here, to run once:
	////////////////////////////LoRa///////////////////////////////////////////////////////////////


	  //Initialize serial and wait for port to open:

	  Serial1.begin(115200);
	  SerialASC.begin(9600);

	  //Initialize LoRaMOTE:

	  delay(10000);
	  Serial1.write(initATZ);
	  Serial1.flush();
	  delay(2000);
	  Serial1.write(initATZ);
	  Serial1.flush();
	  delay(2000);
	  Serial1.write(initAT0);
	  Serial1.flush();

	  //Test display the size of GPS structure:

	  //SerialASC.print(struct_size);

}


void loop()
{
	// put your main code here, to run repeatedly:
	////////////////////////////LoRa////////////////////////////////////////////////////////////////

	//Display DataRX of LoRaMOTE:
/*
	 while (Serial1.available())
	     {
		  data = Serial1.read();
	      SerialASC.print(data);
	     }
*/
//Data serialized_data;

	 //GPS message:
	 gps_struct_t message = {15,15,255,15,15,255,255,15,15,conv_alt,conv_lati,conv_longi,255,127};

	 //Fonction for send GPS message to Serial PORT:
	 send_struct_to_serial (prefix, struct_size, &message);



delay(1000);


}


void setup1()
{

	////////////////////////////GPS///////////////////////////////////////////////////////////////
	//Initialize serial and wait for port to open:

	Serial0.begin(9600);

}


void loop1()
{

	////////////////////////////GPS///////////////////////////////////////////////////////////////
	while (Serial0.available())
	     {
          data2 = Serial0.read();
    	  //Test display the GPS message:
		  //SerialASC.print(data2);

		  dataGPS.encode(data2);
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

		 }
	conv_alt=(short)altitude;
	conv_longi=(float)longitude;
	conv_lati=(float)latitude;

	a = sizeof(conv_alt);
	b = sizeof(conv_longi);
	c = sizeof(conv_lati);
cpt++;
}


void setup2()
{

	Serial.begin(9600);

}


void loop2()
{




}
