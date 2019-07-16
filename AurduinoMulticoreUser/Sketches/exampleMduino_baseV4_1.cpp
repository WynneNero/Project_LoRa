/*
Industrial Shields
www.industrialshields.com
march/2015

  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
#pragma GCC optimize "-O0"

// NOTE: IMPORTANT ACTIVATE/DESACTIVATE APROPIATE INPUT/OUTPUT
// M-Duino 21 IOs have I0X, Q0X
// M-Duino 42 IOs have I0x + I1X, Q0X + Q1X
// M-Duino 58 IOs have I0x + I1X + I2X , Q0X + Q1X + Q2X

//Configuration Digital IN (24Vdc) INTERRUPT IN
int I06 = 3; //INTERRUPT #1
int I05 = 2; //INTERRUPT #0
int I16 = 19; //INTERRUPT #4
int I15 = 18; //INTERRUPT #5
int I26 = 21; //INTERRUPT #2
int I25 = 20; //INTERRUPT #3

//Configuration Digital IN (24Vdc)

int I04 = 26;    // select the Analog/PWM Digital IN
int I03 = 25;    // Digital IN
int I02 = 24;    // Digital IN
int I01 = 23;    // Digital IN
int I00 = 22;    // Digital IN
int I14 = 31;    // Digital IN
int I13 = 30;    // Digital IN
int I12 = 29;    // Digital IN
int I11 = 28;    // Digital IN
int I10 = 27;    // Digital IN
int I23 = 35;    // Digital IN
int I22 = 34;    // Digital IN
int I21 = 33;    // Digital IN
int I20 = 32;    // Digital IN

//Configuration Analog/PWM/Digital IN (0-10Vdc or 24Vdc)
int Q05 = 4;    // select the Analog/PWM Digital OUT
int Q06 = 5;    // select the Analog/PWM Digital OUT
int Q07 = 6;    // select the Analog/PWM Digital OUT
int Q15 = 8;    // select the Analog/PWM Digital OUT
int Q16 = 7;    // select the Analog/PWM Digital OUT
int Q17 = 9;    // select the Analog/PWM Digital OUT
int Q25 = 12;    // select the Analog/PWM Digital OUT
int Q26 = 13;    // select the Analog/PWM Digital OUT

//Configuration Digital OUT (24Vdc)
int Q00 = 36;    // Digital OUT
int Q01 = 37;    // Digital OUT
int Q02 = 38;    // Digital OUT
int Q03 = 39;    // Digital OUT
int Q04 = 40;    // Digital OUT
int Q10 = 41;    // Digital OUT
int Q11 = 42;    // Digital OUT
int Q12 = 43;    // Digital OUT
int Q13 = 44;    // Digital OUT
int Q14 = 45;    // Digital OUT
int Q20 = 46;    // Digital OUT
int Q21 = 47;    // Digital OUT
int Q22 = 48;    // Digital OUT
int Q23 = 49;    // Digital OUT

volatile int state = LOW;

// Shield uses p53 as chipselect
#define SPI_ETHERNET 53

////////////
// Ethernet
////////////
#include<Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Use a fixed IP address
#define USE_FIXED_IP

#ifdef USE_FIXED_IP

IPAddress ip(192, 168, 3, 177);  // For Hitex UK internal network.  Yours may be different!

#endif

unsigned int localPort = 8888;       // local port to listen for UDP packets

char timeServer[] = "time.nist.gov"; // time.nist.gov NTP server

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message

byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

// send an NTP request to the time server at the given address
void sendNTPpacket(char* address);


////////////

// the setup routine runs once when you press reset:
void setup() {       

  pinMode(SPI_ETHERNET, OUTPUT);
  digitalWrite(SPI_ETHERNET,LOW);

  //Configuration Analog/PWM/Digital OUT (0-10Vdc or 24Vdc)  
  pinMode(Q05, OUTPUT);  
  pinMode(Q06, OUTPUT);  
  pinMode(Q07, OUTPUT);  
  pinMode(Q15, OUTPUT);  
  pinMode(Q16, OUTPUT);  
  pinMode(Q17, OUTPUT);  
  pinMode(Q26, OUTPUT);  
  pinMode(Q25, OUTPUT);  
    
  //Configuration Digital IN (24Vdc)  
  pinMode(I00, INPUT);     
  pinMode(I01, INPUT);     
  pinMode(I02, INPUT);     
  pinMode(I03, INPUT);
  pinMode(I04, INPUT);  
  pinMode(I10, INPUT);     
  pinMode(I11, INPUT);     
  pinMode(I12, INPUT);     
  pinMode(I13, INPUT);     
  pinMode(I14, INPUT);     
  pinMode(I20, INPUT);
  pinMode(I21, INPUT);  
  pinMode(I22, INPUT);     
  pinMode(I23, INPUT); 

  pinMode(I05, INPUT);     
  pinMode(I06, INPUT);     
  pinMode(I15, INPUT);
  pinMode(I16, INPUT);  
  pinMode(I25, INPUT);     
  pinMode(I26, INPUT); 

    
  //Configuration Digital OUT (24Vdc)
  pinMode(Q00, OUTPUT);     
  pinMode(Q01, OUTPUT);     
  pinMode(Q02, OUTPUT);     
  pinMode(Q03, OUTPUT);
  pinMode(Q04, OUTPUT);
  pinMode(Q10, OUTPUT);     
  pinMode(Q11, OUTPUT);     
  pinMode(Q12, OUTPUT);     
  pinMode(Q13, OUTPUT);
  pinMode(Q14, OUTPUT);
  pinMode(Q20, OUTPUT);     
  pinMode(Q21, OUTPUT);     
  pinMode(Q22, OUTPUT);     
  pinMode(Q23, OUTPUT);

////////////
// Ethernet
////////////
  Serial1.begin(9600);
  
  // Open serial communications and wait for port to open:
  Serial1.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

#ifdef USE_FIXED_IP

  // start Ethernet and UDP
  Ethernet.begin(mac, ip);

#else

  if (Ethernet.begin(mac, ip) == 0) {
    Serial1.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for (;;)
      ;
  }

#endif
  
  Udp.begin(localPort);
////////////   
}

// the loop routine runs over and over again forever:
void loop() {

  sendNTPpacket(timeServer); // send an NTP packet to a time server

   // wait to see if a reply is available
  delay(500);

  digitalWrite(Q00, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q01, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q02, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q03, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q04, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q05, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q06, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q07, LOW);   // turn the LED on (HIGH is the voltage level)

  delay(500);               // wait for a second
  digitalWrite(Q00, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q01, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q02, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q03, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q04, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q05, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q06, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(Q07, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);     // wait for a second

////////////
// Ethernet
////////////
  if ( Udp.parsePacket() ) {
      // We've received a packet, read the data from it
      Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

      //the timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, extract the two words:

      unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
      unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      Serial1.println("------------------------------------");
      Serial1.print("Seconds since Jan 1 1900 = " );
      Serial1.println(secsSince1900);

      // now convert NTP time into everyday time:
      Serial1.print("Unix time = ");
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long epoch = secsSince1900 - seventyYears;
      // print Unix time:
      Serial1.println(epoch);


      // print the hour, minute and second:
      Serial1.print("The UTC time is ");       // UTC is the time at Greenwich Meridian (GMT)
      Serial1.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day)
      Serial1.print(':');
      if ( ((epoch % 3600) / 60) < 10 ) {
        // In the first 10 minutes of each hour, we'll want a leading '0'
        Serial1.print('0');
      }
      Serial1.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
      Serial1.print(':');
      if ( (epoch % 60) < 10 ) {
        // In the first 10 seconds of each minute, we'll want a leading '0'
        Serial1.print('0');
      }
      Serial1.println(epoch % 60); // print the second
    }
////////////
}


// send an NTP request to the time server at the given address
void sendNTPpacket(char* address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}



/*** Core 1 ***/

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have no initial values here e.g. uint32 CPU1_var; */
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have an initial value here e.g. uint32 CPU1_var_init = 1; */
EndOfInitialised_CPU1_Variables

void setup1() {
  // put your setup code for core 1 here, to run once:


}


void loop1() {
  // put your main code for core 1 here, to run repeatedly:


}



/*** Core 2 ***/

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have no initial values here e.g. uint32 CPU2_var; */
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have an initial value here e.g. uint32 CPU2_var_init = 1; */
EndOfInitialised_CPU2_Variables


void setup2() {
  // put your setup code for core 2 here, to run once:


}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:


}

