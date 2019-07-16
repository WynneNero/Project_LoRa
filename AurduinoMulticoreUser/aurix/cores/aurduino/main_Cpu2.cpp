/*
 * main.cpp
 *
 *  Created on: 26 Mar 2015
 *      Author: smccumiskey
 */

#include "system_tc2x.h"



extern void init();

extern void setup2();

extern void loop2();

#ifdef __cplusplus
extern "C" {
#endif

void main_CPU2(void){

	init();

	setup2();

	while(1){
		loop2();
	}


}


#ifdef __cplusplus
}
#endif
