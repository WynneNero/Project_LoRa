#include "SPI.h"
#include "Ethernet.h"


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
/*IPAddress ip(192,168,3, 177);
IPAddress gateway(192,168,3, 1);
IPAddress subnet(255, 255, 255, 0);*/


// telnet defaults to port 23
EthernetServer server(23);
boolean alreadyConnected = false; // whether or not the client was connected previously


void setup() {

	 pinMode(53, OUTPUT);
	 digitalWrite(53, LOW);  // Required for Industrial Shield

	 SerialASC.begin(9600);
	 SerialASC.println("Starting Chat Server...");

	 /* Make sure other pins on P50-53 are inactive */
	 IfxPort_setPinMode(&MODULE_P33, 4, IfxPort_Mode_inputNoPullDevice);
	 IfxPort_setPinMode(&MODULE_P02, 8, IfxPort_Mode_inputNoPullDevice);
	 IfxPort_setPinMode(&MODULE_P11, 12, IfxPort_Mode_inputNoPullDevice);
	 IfxPort_setPinMode(&MODULE_P33, 5, IfxPort_Mode_inputNoPullDevice);

	 /* Make sure other pins on P201 are inactive */
	 IfxPort_setPinMode(&MODULE_P22, 1, IfxPort_Mode_inputNoPullDevice);
	 IfxPort_setPinMode(&MODULE_P22, 3, IfxPort_Mode_inputNoPullDevice);
	 IfxPort_setPinMode(&MODULE_P22, 0, IfxPort_Mode_inputNoPullDevice);

	 // initialize the ethernet device
	 Ethernet.begin(mac);

	 // start listening for clients
	 server.begin();

	 // Open serial communications and wait for port to open:
	 while (!SerialASC) {
		 ; // wait for serial port to connect. Needed for Leonardo only
	 }

	 SerialASC.print("Chat server address:");
	 SerialASC.println(Ethernet.localIP());
}

void loop() {
	// wait for a new client:
	EthernetClient client = server.available();
	uint8_t i;

	// when the client sends the first byte, say hello:
	if (client) {
		if (!alreadyConnected) {
			// clead out the input buffer:
			client.flush();
			SerialASC.println("We have a new client");
			client.println("Hello, client!");
			alreadyConnected = true;
		}

	if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();
      // echo the bytes back to the client:
      //server.write(thisChar);
      // echo the bytes to the server as well:
      SerialASC.write(thisChar);
    }  }
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




