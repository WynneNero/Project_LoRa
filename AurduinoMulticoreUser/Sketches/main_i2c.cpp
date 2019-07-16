/*
 * main_i2c.cpp
 *
 *  Created on: 1 Apr 2015
 *      Author: smccumiskey
 */

#include "Wire.h"

TwoWire TWI;
uint8_t data_to_write[3] = {0x00,0x01,0x55};
uint8_t mem_addr[2] = {0x00,0x01};
uint8_t ret_bytes[256];

void setup(void){
	uint8 i;
	TWI.begin();
	//TWI.requestFrom(0x05,5);
	//ret_byte = TWI.findAddress();
	/*TWI.beginTransmission(0x50);
	TWI.write(data_to_write,3);
	TWI.endTransmission();*/
	for(i=0;i<255;i++){
		data_to_write[1] = i;
		data_to_write[2] = i;
		TWI.beginTransmission(0x50);
		TWI.write(data_to_write,3);
		TWI.endTransmission();
	}
}

void loop(void){
	uint8 i;
	/*for(i=0;i<255;i++){
		data_to_write[2] = i;
		TWI.beginTransmission(0x50);
		TWI.write(data_to_write,3);
		TWI.endTransmission();
	}*/
	for(i=0;i<255;i++){
		mem_addr[1] = i;
		TWI.beginTransmission(0x50);
		TWI.write(mem_addr,2);
		TWI.endTransmission();
		TWI.requestFrom(0x50,1);
		ret_bytes[i] = TWI.read();
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




