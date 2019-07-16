/*
 * main.cpp
 *
 *  Created on: 26 Mar 2015
 *      Author: smccumiskey
 */

#include "system_tc2x.h"

extern void init();

extern void setup1();

extern void loop1();

#ifdef __cplusplus
extern "C" {
#endif

void main_CPU1(void){

	init();

	setup1();

	while(1){
		loop1();
	}


}


#ifdef __cplusplus
}
#endif
