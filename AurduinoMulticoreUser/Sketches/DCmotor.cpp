/*Sketch to drive Brushed DC-Motor in two directions*/

void reset_ports();

#define  IS_1  0
#define  IS_2  1
#define  IN_1  3
#define  IN_2  11
#define  INH_1 12
#define  INH_2 13

#define TCONST 100      //Delay Time between Steps

int volatile Motor_DC     = 0;    // actual DC
int volatile Motor_DC_MAX = 60;   // 50% Dutycycle

int i = 0;

void setup() {

  // put your setup code here, to run once:
  pinMode(IN_1,OUTPUT);  // D3
  pinMode(IN_2,OUTPUT);  // D11
  pinMode(INH_1,OUTPUT); // D12
  pinMode(INH_2,OUTPUT); // D13

  reset_ports();
  
  digitalWrite(INH_1,1);
  digitalWrite(INH_2,1);

  useArduinoPwmFreq();

}

void fade_Motor(int port)
{
   for(i = 0; i< Motor_DC_MAX; i++)
  {
  Motor_DC = map( i , 0 , 100 , 0 , 255 );
  analogWrite( port , Motor_DC );

  delay(TCONST);
  }
  
  //Slow down Motor
  for(i = Motor_DC_MAX; i>= 0; i--)
  {
  Motor_DC = map( i , 0 , 100 , 0 , 255 );
  analogWrite( port , Motor_DC );

  delay(TCONST);
  }
}

//Alle IOs zurücksetzen
void reset_ports()
{
  digitalWrite(IN_1,0);
  digitalWrite(IN_2,0);
}

void loop() {

 
  //Fade Motor in forward direction
  fade_Motor(IN_2);
  
  //Wait and Stop
  reset_ports();
  delay(1000);  //Wait for 1s
  
  //Fade Motor in backward direction
  fade_Motor(IN_1);
  
  //Wait and Stop
  reset_ports();
  delay(1000);  //Wait for 1s
  
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
