
/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	Serial.begin(9600);
}

char const Message0[] = { "Core0" };

void loop() {
  // put your main code for core 0 here, to run repeatedly:

	Serial.print("\n\rHello from Core0");  //  The pointer to the string seems to get set to NULL, causing a trap!

}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:

	SerialASC.begin(9600);

	// Enable the LED pin
	pinMode(13, OUTPUT);
}

void loop1() {
  // put your main code core 1 here, to run repeatedly:


	/* Has core 2 put the pin high? */
    if(digitalRead(13) == HIGH)
    {
    	delay(500);
    	digitalWrite(13,LOW);
    }

    SerialASC.print("\n\rHello from Core1");  //  The pointer to the string seems to get set to NULL, causing a trap!

}



/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:

	Serial1.begin(9600);

}

void loop2() {
  // put your main code core 2 here, to run repeatedly:


	/* Has core 1 put the pin low? */
    if(digitalRead(13) == LOW)
    {
    	delay(500);
    	digitalWrite(13,HIGH);

    }

	Serial1.print("\n\rHello from Core2");  //  The pointer to the string seems to get set to NULL, causing a trap!


}

