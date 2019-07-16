#include "arduino.h"




/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

	CAN0_Init(250000); // CANRX/CANTX
	CAN3_Init(250000); // DAC0/Pin52

	/* Parameters CAN ID, Acceptance mask, data length, 11 or 29 bit ID, Message object to use */
	CAN0_TxInit(0x100, 0x1FFFFFFFUL, 8, 29, 0);
	//CAN3_TxInit(0x100, 0x1FFFFFFFUL, 8, 11, 0);

	CAN3_RxInit(0x100, 0x1FFFFFFFUL, 8, 29, 1);
	//CAN0_RxInit(0x100, 0x1FFFFFFFUL, 8, 11, 1);

	/* Dual Test */
	CAN0_TxInit(0x101, 0x1FFFFFFFUL, 8, 29, 2);
	CAN3_RxInit(0x101, 0x1FFFFFFFUL, 8, 29, 3);

	/* Triple Test */
	CAN3_TxInit(0x102, 0x1FFFFFFFUL, 8, 29, 4);
	CAN0_RxInit(0x102, 0x1FFFFFFFUL, 8, 29, 5);

    SerialASC.print("Multican is Initialized\n\r");

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:

    IfxMultican_Message msg1;
	IfxMultican_Status RxStatus;
	CANMessagePayloadType CANMessagePayload;
    uint32       errors   = 0;


		const uint32 dataLow  = 0x12340000;
	    const uint32 dataHigh = 0x9abc0000;

	    CANMessagePayload.bytes[0] = 0x00; // 0x12 34 00 00
	    CANMessagePayload.bytes[1] = 0x00;
	    CANMessagePayload.bytes[2] = 0x34;
	    CANMessagePayload.bytes[3] = 0x12;
	    CANMessagePayload.bytes[4] = 0x00; // 0x9a bc 00 00
	    CANMessagePayload.bytes[5] = 0x00;
	    CANMessagePayload.bytes[6] = 0xBC;
	    CANMessagePayload.bytes[7] = 0x9A;

	    /* Transmit Data */
	    {

	    	/* Parameters CAN ID, 32 bits low data, 32 bits high data, data length */
	    	CAN0_SendMessage(0x100, CANMessagePayload.dword[0], CANMessagePayload.dword[1], 8); // Original
	    	//CAN3_SendMessage(0x100, 0x12340000, 0x9abc0000, 8);

	    	/* Dual test */
	    	CAN0_SendMessage(0x101, 0x12340000, 0x9abc0000, 8); // Original

	    	/* Triple Test */
	    	CAN3_SendMessage(0x102, 0x12340000, 0x9abc0000, 8); // Original
	    }

	    /* Receiving Data */
	    {
	        /* wait until MCAN received the frame */

	    	/* Test 1 */
	    	/* Parameters CAN ID, address of structure to hold returned data, data length */
	    	RxStatus = CAN3_ReceiveMessage(0x100, &msg1, 8); // Original

	    	if (RxStatus != IfxMultican_Status_noError)
	    	{
	    	     SerialASC.print("ERROR: single IfxMultican_Can_MsgObj_read Message returned ");SerialASC.print(RxStatus,HEX); SerialASC.print("\n\r");
	    	}


	    	SerialASC.print("Received ID = ");SerialASC.println(msg1.id,HEX);

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

	        /* Test 2 */
	      	RxStatus = CAN3_ReceiveMessage(0x101, &msg1, 8);

   	    	if (RxStatus != IfxMultican_Status_noError)
   	    	{
  	    	     SerialASC.print("ERROR: dual test IfxMultican_Can_MsgObj_read Message returned ");SerialASC.print(RxStatus,HEX); SerialASC.print("\n\r");
  	    	}

   	    	SerialASC.print("Received ID = ");SerialASC.println(msg1.id,HEX);

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
	        	SerialASC.print("OK: Checks dual test passed\n\r");
	        }

	        /* Test 3 */
	      	RxStatus = CAN0_ReceiveMessage(0x102, &msg1, 8);

	   	    if (RxStatus != IfxMultican_Status_noError)
	   	    {
	  	    	SerialASC.print("ERROR: triple test IfxMultican_Can_MsgObj_read Message returned ");SerialASC.print(RxStatus,HEX); SerialASC.print("\n\r");
	   	    }

	   	    SerialASC.print("Received ID = ");SerialASC.println(msg1.id,HEX);

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
		        SerialASC.print("OK: Checks triple test passed\n\r");
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



