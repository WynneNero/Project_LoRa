
/* Allow use of VT100 escape sequences */
#include "vt100.h"

// int_dsprcpu1 .CPU1.csa

#define VADCBufferSize  256



/* CPU0 Uninitialised Data */
#pragma section "int_dsprcpu0.CPU0.bss" awB
uint16 volatile CPU0_var;
#pragma section

/* CPU0 Initialised Data */
#pragma section "int_dsprcpu0.CPU0.data" aw
uint16 volatile CPU0_var_init = 1;
#pragma section

/* CPU1 Uninitialised Data */
#pragma section "int_dsprcpu1.CPU1.bss" awB
uint16 volatile VADC_result[VADCBufferSize];
uint16 volatile CPU1_var;
#pragma section

/* CPU1 Initialised Data */
#pragma section "int_dsprcpu1.CPU1.data" aw
uint16 volatile CPU1_var_init = 1;
#pragma section

/* CPU2 Uninitialised Data */
#pragma section "int_dsprcpu2.CPU2.bss" awB
uint16 volatile CPU2_var;
#pragma section

/* CPU2 Initialised Data */
#pragma section "int_dsprcpu2.CPU2.data" aw
uint16 volatile CPU2_var_init = 1;
#pragma section

/* LMU uninitialised data */
#pragma section ".zbss"
uint16 volatile LMU_var;
#pragma section

/* LMU uninitialised data */
#pragma section ".zdata"
uint16 volatile LMU_var_init = 1;
#pragma section


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	analogReadResolution(8);

	SerialASC.begin(9600);

	SerialASC.print(VT100_CURSOR_OFF);
	SerialASC.print(VT100_CLR_SCREEN);

	pinMode(0, OUTPUT);  // P15.3



}



void loop() {
    // put your main code for core 0 here, to run repeatedly:

	CPU0_var ^= 1;

	CPU0_var_init = 2; // Short addressing to 0xD0000000
	LMU_var_init = 1;
	LMU_var = 2;

	CPU1_var = 3;  // Long addressing to 0x70000000

}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:

}

void loop1() {
  // put your main code core 1 here, to run repeatedly:
	int i;

	SerialASC.print(VT100_CURSOR_HOME);

	for(i = 0 ; i < VADCBufferSize; i++)
	{

		//VADC_result[i] = analogRead(0);
		P15_OUT.B.P3 = 1;
		VADC_result[i] = ReadAD0();
		P15_OUT.B.P3 = 0;
	}

	for(i = 0 ; i < VADCBufferSize; i++)
	{

		SerialASC.print("\n\rAD");SerialASC.print(i);SerialASC.print(" = ");SerialASC.print(VADC_result[i]);SerialASC.print("       ");
		if(i%20 == 0)
		{

			SerialASC.print(VT100_CURSOR_HOME);
		}
	}

}



/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:

	CPU2_var_init = 2;

}

void loop2() {
  // put your main code core 2 here, to run repeatedly:

	CPU2_var ^= 1;

}







