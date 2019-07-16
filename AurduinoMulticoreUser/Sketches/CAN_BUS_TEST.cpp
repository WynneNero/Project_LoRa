/* Include */
#include "arduino.h"

uint LowerData, UpperData ;

int cpt=0, cpt1=0, cpt2=0, cpt3=0;


/* Simple Board Test Sketch */



void setup() {


	    ////////////////////////////CAN BUS TEST////////////////////////////////////////////////////////////////

	    CAN0_Init(250000);
	    CAN1_Init(250000);
	    /* Parameters CAN ID, Acceptance mask, data length, */
	    /* 11 or 29 bit ID, Message object to use */
	    CAN0_TxInit(0x100, 0x7FFFFFFFUL, 8, 11, 0);

	    /* Parameters CAN ID, Acceptance mask, data length, */
	    /* 11 or 29 bit ID, Message object to use */
	    CAN1_RxInit(0x100, 0x7FFFFFFFUL, 8, 11, 1);

	    SerialASC.begin(9600);



}


void loop()
{
	// put your main code here, to run repeatedly:
	IfxMultican_Status RxStatus;
	 IfxMultican_Message msg1;

 	 ////////////////////////////CAN BUS TEST////////////////////////////////////////////////////////////////
	 cpt++;


	/* Parameters CAN ID, 32 bits low data, 32 bits high data, data length */
	CAN0_SendMessage(0x100, 0x12340000, 0x9abc0000, 8);

	cpt1++;

	/* Parameters CAN ID, address of structure to hold returned data, data length */
	RxStatus = CAN1_ReceiveMessage(0x100, &msg1, 8);
	cpt2++;

	//The data received can be accessed in:

	LowerData = msg1.data[0];
	UpperData = msg1.data[1];

	cpt3++;





}




void setup1()
{



}


void loop1()
{



}


void setup2()
{



}


void loop2()
{




}
