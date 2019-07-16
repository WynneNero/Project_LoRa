#include <Wire.h>

#include <Adafruit_Sensor.h>

#include <Adafruit_LSM303_U.h>



/* Assign a unique ID to this sensor at the same time */

Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

/* LMU uninitialised data */

StartOfUninitialised_LMURam_Variables

/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */

EndOfUninitialised_LMURam_Variables



/* LMU uninitialised data */

StartOfInitialised_LMURam_Variables

/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */

EndOfInitialised_LMURam_Variables



/* If you do not care where variables end up, declare them here! */

void displaySensorDetails(void)

{

  sensor_t sensor;

  accel.getSensor(&sensor);

  SerialASC.println("------------------------------------");

  SerialASC.print  ("Sensor:       "); SerialASC.println(sensor.name);

  SerialASC.print  ("Driver Ver:   "); SerialASC.println(sensor.version);

  SerialASC.print  ("Unique ID:    "); SerialASC.println(sensor.sensor_id);

  SerialASC.print  ("Max Value:    "); SerialASC.print(sensor.max_value); SerialASC.println(" m/s^2");

  SerialASC.print  ("Min Value:    "); SerialASC.print(sensor.min_value); SerialASC.println(" m/s^2");

  SerialASC.print  ("Resolution:   "); SerialASC.print(sensor.resolution); SerialASC.println(" m/s^2");

  SerialASC.println("------------------------------------");

  SerialASC.println("");

  delay(500);

}

/*** Core 0 ***/



void setup() 

{

  SerialASC.begin(115200);

  SerialASC.println("Accelerometer Test"); SerialASC.println("");



  /* Initialise the sensor */

  if(!accel.begin())

  {

    /* There was a problem detecting the ADXL345 ... check your connections */

    SerialASC.println("Ooops, no LSM303 detected ... Check your wiring!");

    while(1);

  }

  /* Display some basic information on this sensor */

  displaySensorDetails();

}

void loop() 

{

  SerialASC.println("Loop start");

  /* Get a new sensor event */

  sensors_event_t event;

  SerialASC.println("sensors_event_t event was passed");

  accel.getEvent(&event);                                      // This is a problem !!!!!

  SerialASC.println("accel.getEvent(&event) was passed");

  /* Display the results (acceleration is measured in m/s^2) */

  SerialASC.print("X: "); SerialASC.print(event.acceleration.x); SerialASC.print("  ");

  SerialASC.print("Y: "); SerialASC.print(event.acceleration.y); SerialASC.print("  ");

  SerialASC.print("Z: "); SerialASC.print(event.acceleration.z); SerialASC.print("  ");SerialASC.println("m/s^2 ");



  /* Note: You can also get the raw (non unified values) for */

  /* the last data sample as follows. The .getEvent call populates */

  /* the raw values used below. */

  //Serial.print("X Raw: "); Serial.print(accel.raw.x); Serial.print("  ");

  //Serial.print("Y Raw: "); Serial.print(accel.raw.y); Serial.print("  ");

  //Serial.print("Z Raw: "); Serial.print(accel.raw.z); Serial.println("");



  /* Delay before the next sample */

  delay(500);

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
