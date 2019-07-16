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

char initATZ[4]={0x41,0x54,0x5A};
char initAT0[4]={0x41,0x54,0x30};
char initQ0[3]={0x51,0x30};

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


 union Data {
             gps_struct_t gps_data;
             uint8_t data[18];
            };

 union Data GPS_union;

 void filled_array ()
 {
 	uint8_t size = sizeof(gps_struct_t);
 	while (Serial0.available())
 			  {
 			   if(Serial0.read()==0x44)
 			     {
 				  if (Serial0.read()==0x12)
 				    {
 	     	         for(int i=0 ;i<size ;i++)
 	     	            {
 	     		         byte_received = Serial0.read();
 	     		         GPS_union.data[i]=byte_received;
 	     	            }
 				    }
 			     }
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

void setup()
{

	Serial.begin(9600);

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

}


void setup1()
{

	Serial1.begin(115200);
	delay(10000);
	Serial1.write(initATZ);
	Serial1.flush();
	delay(2000);
	Serial1.write(initAT0);
	Serial1.flush();
	delay(2000);
	Serial1.write(initQ0);
	Serial1.flush();

}


void loop1()
{

	////////////////////////////SEND GPS_DATA///////////////////////////////////////////////////////////////
	gps_struct_t message = {15,15,255,15,15,255,255,15,15,conv_alt,conv_lati,conv_longi,15,127};
	uint8_t struct_size = sizeof(gps_struct_t);
	send_struct_to_LoRa_Serial1(prefix, struct_size, &message);
	delay(5000);

}


void setup2()
{

	SerialASC.begin(9600);
	Serial0.begin(115200);
	delay(5000);
	Serial0.write(initATZ);
	Serial0.flush();
	delay(2000);
	Serial0.write(initAT0);
	Serial0.flush();


}


void loop2()
{

	filled_array ();

	SerialASC.println("-------- FIX GPS ------------");

	SerialASC.print("LATITUDE="); SerialASC.println(GPS_union.gps_data.lat,4);
	SerialASC.print("LONGITUDE="); SerialASC.println(GPS_union.gps_data.lon,4);
	SerialASC.print("ALTITUDE (m) ="); SerialASC.println(GPS_union.gps_data.alt);


}
