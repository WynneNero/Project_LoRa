/* Include */
#include "arduino.h"
#include "TinyGPS++.h"

TinyGPSPlus dataGPS;

/* Simple Board Test Sketch */

char byte_received;
char GPS_DATA;
double latitude;
double longitude;
double altitude;
short conv_alt=0;
float conv_lati=0;
float conv_longi=0;

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

union Data {
      	gps_struct_t gps_data;
          uint8_t data[18];
};

union Data GPS_union;

void filled_array ()
{
	uint8_t size = sizeof(gps_struct_t);
	while (Serial1.available())
			  {

	     	   for(int i=0 ;i<size ;i++)
	     	   {
	     		  byte_received = Serial1.read();
	     		  GPS_union.data[i]=byte_received;
	     	   }
			  }
}

void send_struct_to_serial0 (uint8_t size, void * data)
{
	uint8_t * iter = (uint8_t *) data;
	for (int i=0;  i < size; i++)
	{
		Serial0.write(*iter);
		iter++;
	}
}


void setup()
{

	Serial.begin(9600);
	Serial0.begin(9600);

}


void loop()
{
	////////////////////////////GPS_DATA///////////////////////////////////////////////////////////////
		while (Serial.available())
			  {
			   GPS_DATA = Serial.read();
		       dataGPS.encode(GPS_DATA);
		       if (dataGPS.location.isUpdated())
		         {
		    	   latitude = dataGPS.location.lat();
		    	   longitude = dataGPS.location.lng();
		    	   altitude = dataGPS.altitude.meters();
		          }
		       conv_alt=(short)altitude;
		       conv_longi=(float)longitude;
		       conv_lati=(float)latitude;
			  }
	////////////////////////////SEND GPS_DATA///////////////////////////////////////////////////////////////
	gps_struct_t message = {15,15,255,15,15,255,255,15,15,conv_alt,conv_lati,conv_longi,15,127};
	uint8_t struct_size = sizeof(gps_struct_t);

	send_struct_to_serial0 (struct_size, &message);

}


void setup1()
{

	Serial1.begin(9600);

}


void loop1()
{

	filled_array ();

}


void setup2()
{

	SerialASC.begin(9600);

}


void loop2()
{



   	SerialASC.println("-------- FIX GPS ------------");

   	SerialASC.print("LATITUDE="); SerialASC.println(GPS_union.gps_data.lat,4);
    SerialASC.print("LONGITUDE="); SerialASC.println(GPS_union.gps_data.lon,4);
   	SerialASC.print("ALTITUDE (m) ="); SerialASC.println(GPS_union.gps_data.alt,4);


}
