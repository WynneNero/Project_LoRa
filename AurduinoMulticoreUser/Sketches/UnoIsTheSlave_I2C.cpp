
#include <Wire.h>




#define _SEND_TO_SLAVE_TEST_    /* Use this with Wire slave_receiver programmed into Arduino Uno */
//#define _READ_FROM_SLAVE_TEST_  /* Use this with Wire slave_sender programmed into Arduino Uno */

uint8 volatile SlaveDeviceAddr;


#ifdef _SEND_TO_SLAVE_TEST_

void setup() {

  Wire.setWirePins(UsePins_20_21); // Default pins for Arduino Due/MEGA
  //Wire.setWirePins(UsePins_16_17); // SDA1/SCL1
  //Wire.setWirePins(UsePins_6_7); // p6, p7 SDA1/SCL1

  Wire.begin(); // join i2c bus (address optional for master)

}

byte x = 0;

void loop() {
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  x++;
  delay(500);
}

#endif


#ifdef _READ_FROM_SLAVE_TEST_

void setup() {

  Wire.setWirePins(UsePins_20_21); // Default pins for Arduino Due/MEGA
  //Wire.setWirePins(UsePins_16_17); // SDA1/SCL1
  //Wire.setWirePins(UsePins_6_7); // p6, p7 SDA1/SCL1
  Wire.setWireBaudrate(100000);    // Set normal speed mode

  Wire.begin();        // join i2c bus (address optional for master)

  SerialASC.begin(9600);  // start serial for output
  SerialASC.println("Starting Test");
}

void loop() {
  Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    SerialASC.print(c);         // print the character
  }

  delay(500);
}

#endif


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

