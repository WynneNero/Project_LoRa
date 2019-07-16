/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

#include "tone.h"
#include "arduino.h"


/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */

uint32 PWM_Period0;
uint32 PWM_Period1;
uint32 PWM_Period2;
uint32 PWM_Duration0;
uint32 PWM_Duration1;
uint32 PWM_Duration2;
float DutyRatio0;
float DutyRatio1;
float DutyRatio2;
float Frequency0;
float Frequency1;
float Frequency2;

/*** Core 0 ***/


void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

	// Create test signals
	useCustomPwmFreq(1000); // Set 1000Hz carrier

	analogWrite(2, 32);  // 12.5% Duty ratio.  Connect to pin 8
	analogWrite(3, 64);  // 25% Duty ratio. Connect to pin 9
	analogWrite(4, 128); // 50% Duty ratio. Connect to pin 10

	// Initialise PWM measurement
	Init_TIM_TPWM(8, TIM_TPWM_RISINGEDGE);
	Init_TIM_TPWM(9, TIM_TPWM_RISINGEDGE);
	Init_TIM_TPWM(10, TIM_TPWM_FALLINGEDGE);  // Assume an inverted PWM signal

}




void loop() {
    // put your main code for core 0 here, to run repeatedly:

	if(MeasurePwm(8, &PWM_Period0, &PWM_Duration0, &DutyRatio0) == PwmMeasurementData)
	{
		// New PWM data available

	}

	if(MeasurePwm(9, &PWM_Period1, &PWM_Duration1, &DutyRatio1) == PwmMeasurementData)
	{
		// New PWM data available

	}

	if(MeasurePwm(10, &PWM_Period2, &PWM_Duration2, &DutyRatio2)  == PwmMeasurementData)
	{
		// New PWM data available

	}

	DutyRatio0 = MeasureDutyRatio(8);
	DutyRatio1 = MeasureDutyRatio(9);
	DutyRatio2 = MeasureDutyRatio(10);

	Frequency0 = MeasureFrequency(8);
	Frequency1 = MeasureFrequency(9);
	Frequency2 = MeasureFrequency(10);

	SerialASC.print("Duty Ratio ");SerialASC.print(0);SerialASC.print(": ");SerialASC.println(DutyRatio0);
	SerialASC.print("Duty Ratio ");SerialASC.print(1);SerialASC.print(": ");SerialASC.println(DutyRatio1);
	SerialASC.print("Duty Ratio ");SerialASC.print(2);SerialASC.print(": ");SerialASC.println(DutyRatio2);

	SerialASC.print("Frequency ");SerialASC.print(0);SerialASC.print(": ");SerialASC.print(Frequency0);SerialASC.println("Hz");
	SerialASC.print("Frequency ");SerialASC.print(1);SerialASC.print(": ");SerialASC.print(Frequency1);SerialASC.println("Hz");
	SerialASC.print("Frequency ");SerialASC.print(2);SerialASC.print(": ");SerialASC.print(Frequency2);SerialASC.println("Hz");

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



