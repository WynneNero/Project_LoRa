
uint32 LEDcount = 0;
uint32 Speed = 4;

uint32 QuadState = 0;
uint32 HallState = 0;

uint32 ChannelA = 0;
uint32 ChannelB = 0;



void QuadEncoderOut(void);
void HallOut(void);

/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(13,OUTPUT); // LED

  digitalWrite(2,0);
  digitalWrite(3,0);

  ChannelA = 1;
  ChannelB = 0;


  // Period = 1000000u => 10ms
  CreateTimerInterrupt(ContinuousTimerInterrupt, 100000u , HallOut);


}

void QuadEncoderOut(void)
{

	switch(QuadState)
	{

		case 0:

			digitalWrite(13, (LEDcount & 0x01));
			LEDcount++;

			digitalWrite(2,1);
			QuadState = 1;

		break;

		case 1:

			digitalWrite(3,1);
			QuadState = 2;

		break;

		case 2:

			digitalWrite(2,0);
			QuadState = 3;

		break;

		case 3:

			digitalWrite(3,0);
			QuadState = 0;

		break;

	}
}


/*
 *
 * U: 1,0,0,0,1,1
 * V: 1,1,1,0,0,0
 * W: 0,0,1,1,1,0
 *
 */

void HallOut(void)
{

	switch(HallState)
	{

		case 0:

			digitalWrite(13, (LEDcount & 0x01));
			LEDcount++;

			digitalWrite(2,1);
			digitalWrite(3,1);
			digitalWrite(4,0);

			HallState = 1;

		break;

		case 1:

			digitalWrite(2,0);
			digitalWrite(3,1);
			digitalWrite(4,0);
			HallState = 2;

		break;

		case 2:

			digitalWrite(2,0);
			digitalWrite(3,1);
			digitalWrite(4,1);
			HallState = 3;

		break;

		case 3:

			digitalWrite(2,0);
			digitalWrite(3,0);
			digitalWrite(4,1);
			HallState = 4;

		break;

		case 4:

			digitalWrite(2,1);
			digitalWrite(3,0);
			digitalWrite(4,1);
			HallState = 5;

		break;

		case 5:

			digitalWrite(2,1);
			digitalWrite(3,0);
			digitalWrite(4,0);
			HallState = 0;

		break;

	}
}



void loop() {
  // put your main code for core 0 here, to run repeatedly:


}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:

}


void loop1() {
  // put your main code core 1 here, to run repeatedly:


}



/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:

}


void loop2() {
  // put your main code core 2 here, to run repeatedly:

}
