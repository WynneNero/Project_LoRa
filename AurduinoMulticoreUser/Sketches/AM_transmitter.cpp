/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

/* Include wav file */
#include "u8Bit_WavIn.h"


/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */

uint32 volatile ModulationFreqAcc;
uint32 volatile ModulationFreq = 256; /* Default: playback at 22050Hz.  changing this will alter the playback speed */

uint32 ModulationMargin = 110;

#define VolumeMaxValue    100
uint32 Volume = 100;

#define PlaybackRate  	4535  /* 4535 = 22050Hz */


/* Prototype for playback interrupt */
void SynthTimebase(void);

/*** Core 0 ***/

/* Setup up DAC0 and DAC1 to transmit an unsigned 8 bit mono wav file on 270kHz and 529kHz AM */

void setup() {
  // put your setup code for core 0 here, to run once:

	// Make a continuous interrupt, period = 10000u => 100us
	CreateTimerInterrupt(ContinuousTimerInterrupt, PlaybackRate, SynthTimebase);

	// Enable the LED pin
	pinMode(13, OUTPUT);

	/* Enable carrier waves (50% duty ratio) */
	analogWrite(DAC0_RF, AnalogOutDAC0_RF_270kHzCarrier/2);
	analogWrite(DAC1_RF, AnalogOutDAC1_RF_529kHzCarrier/2);

}



/* Called every 45.35us (22050Hz) */
void SynthTimebase(void)
{

	uint32 SizeArr;
	uint32 SampleVal1;
	uint8 RawVal;
	uint32 SampleValScaled1;
	uint32 SampleValScaled2;

	/* Get size of sample */
	SizeArr = sizeof(WavInFileName);

	/* Get sample */
	RawVal = WavInFileName[(ModulationFreqAcc/256)%SizeArr];

	SampleVal1 = (uint32)RawVal;

	// Long Wave
	SampleValScaled1 = (Volume * SampleVal1 * (AnalogOutDAC0_RF_270kHzCarrier - ModulationMargin))/((InputWavAudioResolution-1) * VolumeMaxValue);
	SampleValScaled2 = AnalogOutDAC0_RF_270kHzCarrier + SampleValScaled1;

	/* Compensate for rounding errors */
	if(SampleValScaled2 & 1)
	{
		SampleValScaled2++;
	}

	SampleValScaled2 /= 2;

	/* Update PWM sfr directly */
	AnalogOutDAC0_RF_DutyRatio = SampleValScaled2;

	// Medium Wave
	SampleValScaled1 = (Volume * SampleVal1 * (AnalogOutDAC1_RF_529kHzCarrier - ModulationMargin))/((InputWavAudioResolution-1) * VolumeMaxValue);
	SampleValScaled2 = AnalogOutDAC1_RF_529kHzCarrier + SampleValScaled1;

	/* Compensate for rounding errors */
	if(SampleValScaled2 & 1)
	{
		SampleValScaled2++;
	}

	SampleValScaled2 /= 2;

	/* Update PWM sfr directly */
	AnalogOutDAC1_RF_DutyRatio = SampleValScaled2;

	/* Update modulation accumulator */
	ModulationFreqAcc += ModulationFreq;

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:


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

