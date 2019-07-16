
/*** Core 0 ***/
char incoming = 0;

void setup() {
  SerialASC.begin(9600);
}

void loop() {
  if (SerialASC.available() > 0) {
    incoming = SerialASC.read();
    SerialASC.println(incoming);
  }
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
