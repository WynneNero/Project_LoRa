#include "arduino.h"




/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

	CAN0_Init(250000);
	CAN1_Init(250000);


	/* Parameters CAN ID, Acceptance mask, data length, 11 or 29 bit ID, Message object to use */
	CAN0_TxInit(0x100, 0x7FFFFFFFUL, 8, 11, 0);
	//CAN1_TxInit(0x100, 0x7FFFFFFFUL, 8, 11, 0);

	/* Receive all message IDs up t0 0xFFF */
	CAN1_RxInit(0x200, 0x7FFFF000UL, 8, 11, 1);
	
	SerialASC.print("Multican is Initialized\n\r");

}



void loop() {
  // put your main code for core 0 here, to run repeatedly:

    IfxMultican_Message msg1;
	IfxMultican_Status RxStatus;

		const uint32 dataLow  = 0x12340000;
	    const uint32 dataHigh = 0x9abc0000;

	    uint32       errors   = 0;

	    /* Transmit Data */
	    {

	    	/* Parameters CAN ID, 32 bits low data, 32 bits high data, data length */
	    	CAN0_SendMessage(0x100, 0x12340000, 0x9abc0000, 8); // Original
	    	//CAN1_SendMessage(0x100, 0x12340000, 0x9abc0000, 8);

	    }

	    /* Receiving Data */
	    {
	        /* wait until MCAN received the frame */

	    	/* Test 1 */
	    	/* Parameters CAN ID, address of structure to hold returned data, data length */
	    	RxStatus = CAN1_ReceiveMessage(0x200, &msg1, 8); // Original

	    	if (RxStatus != IfxMultican_Status_noError)
	    	{
	    	     SerialASC.print("ERROR: single IfxMultican_Can_MsgObj_read Message returned ");SerialASC.print(RxStatus,HEX); SerialASC.print("\n\r");
	    	}


	        /* check the received data */
	        if (msg1.data[0] != dataLow)
	        {
	            ++errors;
	        }

	        if (msg1.data[1] != dataHigh)
	        {
	            ++errors;
	        }

	        if (errors)
	        {
	        	SerialASC.print("ERROR: Found (errors)");SerialASC.print(errors);SerialASC.print("\n\r");
	        }
	        else
	        {
	        	SerialASC.print("OK: single test Checks passed\n\r");
	        }

	    }

	    SerialASC.print("Multican Basic data transactions are finished\n\r\n\r");

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



