const int
 PWM_A   = 3,
 DIR_A   = 12,
 BRAKE_A = 9,
 SNS_A   = A0;


void setup() {
   // Configure the A output
   pinMode(BRAKE_A, OUTPUT);  // Brake pin on channel A
   pinMode(DIR_A, OUTPUT);    // Direction pin on channel A

   // Open Serial communication
   SerialASC.begin(9600);
   SerialASC.println("Motor shield DC motor Test:\n");
}

void loop() {

// Set the outputs to run the motor forward

   digitalWrite(BRAKE_A, LOW);  // setting brake LOW disable motor brake
   digitalWrite(DIR_A, HIGH);   // setting direction to HIGH the motor will spin forward

   analogWrite(PWM_A, 255);     // Set the speed of the motor, 255 is the maximum value

   delay(5000);                 // hold the motor at full speed for 5 seconds
   SerialASC.print("current consumption at full speed: ");
   SerialASC.println(analogRead(SNS_A));

// Brake the motor

   SerialASC.println("Start braking\n");
   // raising the brake pin the motor will stop faster than the stop by inertia
   digitalWrite(BRAKE_A, HIGH);  // raise the brake
   delay(5000);

// Set the outputs to run the motor backward

   SerialASC.println("Backward");
   digitalWrite(BRAKE_A, LOW);  // setting againg the brake LOW to disable motor brake
   digitalWrite(DIR_A, LOW);    // now change the direction to backward setting LOW the DIR_A pin

   analogWrite(PWM_A, 255);     // Set the speed of the motor

   delay(5000);
   SerialASC.print("current consumption backward: ");
   SerialASC.println(analogRead(SNS_A));

   // now stop the motor by inertia, the motor will stop slower than with the brake function
   analogWrite(PWM_A, 0);       // turn off power to the motor

   SerialASC.print("current brake: ");
   SerialASC.println(analogRead(A0));
   SerialASC.println("End of the motor shield test with DC motors. Thank you!");


   while(1);
}
