/* Include */
#include "arduino.h"


short conv_alt=0;
float conv_longi=0;
float conv_lati=0;

int cpt,cpt1;

char data;

char initATZ[4]={0x41,0x54,0x5A};
char initAT0[4]={0x41,0x54,0x30};

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


/* Simple Board Test Sketch */
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



void setup()
{
	Serial0.begin(115200);
	SerialASC.begin(9600);

	  delay(10000);
	  Serial0.write(initATZ);
	  Serial0.flush();
	  delay(2000);
	  Serial0.write(initATZ);
	  Serial0.flush();
	  delay(2000);
	  Serial0.write(initAT0);
	  Serial0.flush();

}


void loop()
{

	//Display DataRX of LoRaMOTE:

		 while (Serial0.available())
		     {
			  data = Serial0.read();
		      SerialASC.print(data);
		      cpt++;
		     }
		 cpt1++;
	     gps_struct_t message = {15,15,255,15,15,255,255,15,15,conv_alt,conv_lati,conv_longi,15,127};
		 uint8_t struct_size = sizeof(gps_struct_t);
		 send_struct_to_LoRa_Serial0(prefix, struct_size, &message);
		 delay(4000);

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
