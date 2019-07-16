/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

#include <SPI.h>
#include <Ethernet.h>

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */


/*
   Web Server

  A simple web server that shows the value of the analog input pins.
  using an Arduino Wiznet Ethernet shield.

  Circuit:
  * Ethernet shield attached to pins 10, 11, 12, 13
  * Analog inputs attached to pins A0 through A5 (optional)

  created 18 Dec 2009
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe
  modified 02 Sept 2015
  by Arturo Guadalupi

  */



// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
   0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

 IPAddress ip(192, 168, 3, 177);  // For Hitex UK internal network.  Yours may be different!

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
 EthernetServer server(80);


void setup() {
   // Open serial communications and wait for port to open:
   SerialASC.begin(9600);
   while (!Serial) {
     ; // wait for serial port to connect. Needed for native USB port only
   }


   // start the Ethernet connection and the server:
   Ethernet.begin(mac, ip);
   //Ethernet.begin(mac);
   server.begin();
   SerialASC.print("server is at ");
   SerialASC.println(Ethernet.localIP());
}


void loop() {
   // listen for incoming clients
   EthernetClient client = server.available();
   if (client) {
     SerialASC.println("new client");
     // an http request ends with a blank line
     boolean currentLineIsBlank = true;
     while (client.connected()) {
       if (client.available()) {
         char c = client.read();
         SerialASC.write(c);
         // if you've gotten to the end of the line (received a newline
         // character) and the line is blank, the http request has ended,
         // so you can send a reply
         if (c == '\n' && currentLineIsBlank) {
           // send a standard http response header
           client.println("HTTP/1.1 200 OK");
           client.println("Content-Type: text/html");
           client.println("Connection: close");  // the connection will be closed after completion of the response
           client.println("Refresh: 2");  // refresh the page automatically every 2 sec
           client.println();
           client.println("<!DOCTYPE HTML>");
           client.println("<html>");
           client.print("ShieldBuddy Analog Inputs Demo");
           client.println("<br />");
           // output the value of each analog input pin
           for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
             int sensorReading = analogRead(analogChannel);
             client.print("Analog input ");
             client.print(analogChannel);
             client.print(" is ");
             client.print(sensorReading);
             client.println("<br />");
           }
           client.println("</html>");
           break;
         }
         if (c == '\n') {
           // you're starting a new line
           currentLineIsBlank = true;
         } else if (c != '\r') {
           // you've gotten a character on the current line
           currentLineIsBlank = false;
         }
       }
     }
     // give the web browser time to receive the data
     delay(1);
     // close the connection:
     client.stop();
     SerialASC.println("client disconnected");
   }
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



