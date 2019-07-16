/* Include */
#include "arduino.h"

/* Simple Board Test Sketch */

char data;
int cpt=0, cpt1=0, cpt2=0 ,cpt3=0;


char chaine1[]= ">♣37465";
char a[] ="";

char chaine[]={0x41,0x54,0x5A};

// sapakot!!!
__attribute__((packed))
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
       uint16_t    alt;            //
       uint32_t    lat;            //
       uint32_t    lon;            //
       //TStamp_t    stamp;
       uint8_t     tstamp[2];      //kad sanjemts peedeejais GPS, info no hosta
   } message_t;

message_t GPS;

void setup()
{
	// put your setup code here, to run once:
	////////////////////////////LoRa TEST///////////////////////////////////////////////////////////////


	  //Initialize serial and wait for port to open:
	  Serial1.begin(115200);
	  SerialASC.begin(9600);
	  delay(10000);
	  Serial1.print("ATZ");
	  delay(5000);
	  Serial1.print("AT0");
	  delay(5000);

}


void loop()
{
	// put your main code here, to run repeatedly:
	////////////////////////////LoRa TEST////////////////////////////////////////////////////////////////


	 while (Serial1.available())
	     {
		  data = Serial1.read();
	      SerialASC.print(data);
	      cpt++;
	     }
	 cpt1++;


/*
if (chaine1 != a)
	{
	 Serial1.print(chaine1);
	 for(int i=0; 10;i++)
	 	 {
		  a[i]=chaine1[i];
	 	 }
	}
*/

Serial1.print(chaine1);
//Serial1.flush();
//delay(1000);


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
