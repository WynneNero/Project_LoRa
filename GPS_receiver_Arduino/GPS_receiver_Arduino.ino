#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

char initATZ[4]={0x41,0x54,0x5A};
char initAT0[4]={0x41,0x54,0x30};
char byte_received;

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
     while (mySerial.available())
          {
           if(mySerial.read()==0x44)
             {
            if (mySerial.read()==0x12)
              {
                   for(int i=0 ;i<size ;i++)
                      {
                     byte_received = mySerial.read();
                     GPS_union.data[i]=byte_received;
                      }
              }
             }
          }
 }

void setup() 
{

    Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }
    // set the data rate for the SoftwareSerial port
  
    mySerial.begin(115200);
    delay(5000);
    mySerial.write(initATZ);
    mySerial.flush();
    delay(2000);
    mySerial.write(initAT0);
    mySerial.flush();

}


void loop() 
{

  filled_array ();
  Serial.print(GPS_union.gps_data.lat,4);
  Serial.print(",");
  Serial.println(GPS_union.gps_data.lon,4);

}

