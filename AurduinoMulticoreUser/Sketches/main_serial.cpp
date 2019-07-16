/*
 * main_serial.cpp
 *
 *  Created on: 31 Mar 2015
 *      Author: smccumiskey
 */


void setup(){
	SerialASC.begin(9600);
}

void loop(){
	SerialASC.write(SerialASC.read());
}
