// Simple strand test for Adafruit Dot Star RGB LED strip.
// This is a basic diagnostic tool, NOT a graphics demo...helps confirm
// correct wiring and tests each pixel's ability to display red, green
// and blue and to forward data down the line.  By limiting the number
// and color0 of LEDs, it's reasonably safe to power a couple meters off
// the Arduino's 5V pin.  DON'T try that with other code!

#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
//#include <avr/power.h> // ENABLE THIS LINE FOR GEMMA OR TRINKET

#define NUMPIXELS 30 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN_S01 2 //
#define DATAPIN_S02 3 //
#define DATAPIN_S03 4 //
#define DATAPIN_S04 5 //
#define DATAPIN_S05 6 //
#define DATAPIN_S06 7 //
#define DATAPIN_S07 8 //
#define DATAPIN_S08 9 //
#define DATAPIN_S09 10 //
#define DATAPIN_S10 11 //

#define DATAPIN_S11 23 //
#define DATAPIN_S12 24 //
#define DATAPIN_S13 25 //
#define DATAPIN_S14 26 //
#define DATAPIN_S15 27 //
#define DATAPIN_S16 28 //
#define DATAPIN_S17 29 //
#define DATAPIN_S18 30 //
#define DATAPIN_S19 31 //
#define DATAPIN_S20 32 //

#define DATAPIN_S21 34 //
#define DATAPIN_S22 35 //
#define DATAPIN_S23 36 //
#define DATAPIN_S24 37 //
#define DATAPIN_S25 38 //
#define DATAPIN_S26 39 //
#define DATAPIN_S27 40 //
#define DATAPIN_S28 41 //
#define DATAPIN_S29 42 //
#define DATAPIN_S30 43 //

#define CLOCKPIN_Master_0 13 //
#define CLOCKPIN_Master_1 22 //
#define CLOCKPIN_Master_2 33 //

Adafruit_DotStar strip_S01 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S01, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S02 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S02, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S03 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S03, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S04 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S04, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S05 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S05, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S06 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S06, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S07 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S07, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S08 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S08, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S09 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S09, CLOCKPIN_Master_0, DOTSTAR_BGR);
Adafruit_DotStar strip_S10 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S10, CLOCKPIN_Master_0, DOTSTAR_BGR);

Adafruit_DotStar strip_S11 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S11, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S12 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S12, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S13 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S13, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S14 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S14, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S15 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S15, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S16 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S16, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S17 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S17, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S18 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S18, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S19 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S19, CLOCKPIN_Master_1, DOTSTAR_BGR);
Adafruit_DotStar strip_S20 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S20, CLOCKPIN_Master_1, DOTSTAR_BGR);

Adafruit_DotStar strip_S21 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S21, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S22 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S22, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S23 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S23, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S24 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S24, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S25 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S25, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S26 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S26, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S27 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S27, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S28 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S28, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S29 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S29, CLOCKPIN_Master_2, DOTSTAR_BGR);
Adafruit_DotStar strip_S30 = Adafruit_DotStar(NUMPIXELS, DATAPIN_S30, CLOCKPIN_Master_2, DOTSTAR_BGR);

// The last parameter is optional -- this is the color0 data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B color0s, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
//Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);

void setup() {

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip_S01.begin(); // Initialize pins for output
  strip_S01.show();  // Turn all LEDs off ASAP

  strip_S02.begin(); // Initialize pins for output
  strip_S02.show();  // Turn all LEDs off ASAP

  strip_S02.begin(); // Initialize pins for output
  strip_S02.show();  // Turn all LEDs off ASAP

  strip_S03.begin(); // Initialize pins for output
  strip_S03.show();  // Turn all LEDs off ASAP

  strip_S04.begin(); // Initialize pins for output
  strip_S04.show();  // Turn all LEDs off ASAP

  strip_S05.begin(); // Initialize pins for output
  strip_S05.show();  // Turn all LEDs off ASAP

  strip_S06.begin(); // Initialize pins for output
  strip_S06.show();  // Turn all LEDs off ASAP

  strip_S07.begin(); // Initialize pins for output
  strip_S07.show();  // Turn all LEDs off ASAP

  strip_S08.begin(); // Initialize pins for output
  strip_S08.show();  // Turn all LEDs off ASAP

  strip_S09.begin(); // Initialize pins for output
  strip_S09.show();  // Turn all LEDs off ASAP

  strip_S10.begin(); // Initialize pins for output
  strip_S10.show();  // Turn all LEDs off ASAP

  SerialASC.begin(9600);
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.

int      head0  = 0, tail0 = -10; // Index of first 'on' and 'off' pixels
uint32_t color0 = 0xFF0000;      // 'On' color0 (starts red)

int      head1  = 0, tail1 = -10; // Index of first 'on' and 'off' pixels
uint32_t color1 = 0xFF0000;      // 'On' color1 (starts red)

int      head2  = 0, tail2 = -10; // Index of first 'on' and 'off' pixels
uint32_t color2 = 0xFF0000;      // 'On' color2 (starts red)

void loop() {

	strip_S01.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S01.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S01.show();                     // Refresh strip

	strip_S02.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S02.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S02.show();                     // Refresh strip

	strip_S03.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S03.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S03.show();                     // Refresh strip

	strip_S04.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S04.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S04.show();                     // Refresh strip

	strip_S05.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S05.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S05.show();                     // Refresh strip

	strip_S06.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S06.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S06.show();                     // Refresh strip

	strip_S07.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S07.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S07.show();                     // Refresh strip

	strip_S08.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S08.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S08.show();                     // Refresh strip

	strip_S09.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S09.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S09.show();                     // Refresh strip

	strip_S10.setPixelColor(head0, color0); // 'On' pixel at head0
	strip_S10.setPixelColor(tail0, 0);     // 'Off' pixel at tail0
	strip_S10.show();                     // Refresh strip

	delay(20);                        // Pause 20 milliseconds (~50 FPS)

  if(++head0 >= NUMPIXELS) {         // Increment head0 index.  Off end of strip?
    head0 = 0;                       //  Yes, reset head0 index to start
    if((color0 >>= 8) == 0)          //  Next color0 (R->G->B) ... past blue now?
      color0 = 0xFF0000;             //   Yes, reset to red
  }
  if(++tail0 >= NUMPIXELS) tail0 = 0; // Increment, reset tail0 index

	/* If ASC is free lock it */
	while(Htx_LockResource(&SerialASC.PortInUse) == Htx_RESOURCE_BUSY) { ; }

	SerialASC.print("Hello from Core 0\n\r");

	Htx_UnlockResource(&SerialASC.PortInUse);

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

	strip_S11.begin(); // Initialize pins for output
	strip_S11.show();  // Turn all LEDs off ASAP

	strip_S12.begin(); // Initialize pins for output
	strip_S12.show();  // Turn all LEDs off ASAP

	strip_S13.begin(); // Initialize pins for output
	strip_S13.show();  // Turn all LEDs off ASAP

	strip_S14.begin(); // Initialize pins for output
	strip_S14.show();  // Turn all LEDs off ASAP

	strip_S15.begin(); // Initialize pins for output
	strip_S15.show();  // Turn all LEDs off ASAP

	strip_S16.begin(); // Initialize pins for output
	strip_S16.show();  // Turn all LEDs off ASAP

	strip_S17.begin(); // Initialize pins for output
	strip_S17.show();  // Turn all LEDs off ASAP

	strip_S18.begin(); // Initialize pins for output
	strip_S18.show();  // Turn all LEDs off ASAP

	strip_S19.begin(); // Initialize pins for output
	strip_S19.show();  // Turn all LEDs off ASAP

	strip_S20.begin(); // Initialize pins for output
	strip_S20.show();  // Turn all LEDs off ASAP


}

void loop1() {
  // put your main code for core 1 here, to run repeatedly:

	strip_S11.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S11.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S11.show();                     // Refresh strip

	strip_S12.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S12.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S12.show();                     // Refresh strip

	strip_S13.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S13.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S13.show();                     // Refresh strip

	strip_S14.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S14.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S14.show();                     // Refresh strip

	strip_S15.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S15.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S15.show();                     // Refresh strip

	strip_S16.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S16.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S16.show();                     // Refresh strip

	strip_S17.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S17.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S17.show();                     // Refresh strip

	strip_S18.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S18.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S18.show();                     // Refresh strip

	strip_S19.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S19.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S19.show();                     // Refresh strip

	strip_S20.setPixelColor(head1, color1); // 'On' pixel at head1
	strip_S20.setPixelColor(tail1, 0);     // 'Off' pixel at tail1
	strip_S20.show();                     // Refresh strip

	//delay(20); /* Make it look like this core is doing something useful! */

	 if(++head1 >= NUMPIXELS) {         // Increment head0 index.  Off end of strip?
	    head1 = 0;                       //  Yes, reset head0 index to start
	    if((color1 >>= 8) == 0)          //  Next color0 (R->G->B) ... past blue now?
	      color1 = 0xFF0000;             //   Yes, reset to red
	  }
	  if(++tail1 >= NUMPIXELS) tail1 = 0; // Increment, reset tail0 index


	while(Htx_LockResource(&SerialASC.PortInUse) == Htx_RESOURCE_BUSY) { ; }

	SerialASC.print("Hello from Core 1\n\r");

	Htx_UnlockResource(&SerialASC.PortInUse);

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

	strip_S21.begin(); // Initialize pins for output
	strip_S21.show();  // Turn all LEDs off ASAP

	strip_S22.begin(); // Initialize pins for output
	strip_S22.show();  // Turn all LEDs off ASAP

	strip_S23.begin(); // Initialize pins for output
	strip_S23.show();  // Turn all LEDs off ASAP

	strip_S24.begin(); // Initialize pins for output
	strip_S24.show();  // Turn all LEDs off ASAP

	strip_S25.begin(); // Initialize pins for output
	strip_S25.show();  // Turn all LEDs off ASAP

	strip_S26.begin(); // Initialize pins for output
	strip_S26.show();  // Turn all LEDs off ASAP

	strip_S27.begin(); // Initialize pins for output
	strip_S27.show();  // Turn all LEDs off ASAP

	strip_S28.begin(); // Initialize pins for output
	strip_S28.show();  // Turn all LEDs off ASAP

	strip_S29.begin(); // Initialize pins for output
	strip_S29.show();  // Turn all LEDs off ASAP

	strip_S30.begin(); // Initialize pins for output
	strip_S30.show();  // Turn all LEDs off ASAP

}

void loop2() {
  // put your main code for core 2 here, to run repeatedly:

	strip_S21.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S21.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S21.show();                     // Refresh strip

	strip_S22.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S22.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S22.show();                     // Refresh strip

	strip_S23.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S23.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S23.show();                     // Refresh strip

	strip_S24.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S24.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S24.show();                     // Refresh strip

	strip_S25.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S25.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S25.show();                     // Refresh strip

	strip_S26.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S26.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S26.show();                     // Refresh strip

	strip_S27.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S27.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S27.show();                     // Refresh strip

	strip_S28.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S28.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S28.show();                     // Refresh strip

	strip_S29.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S29.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S29.show();                     // Refresh strip

	strip_S30.setPixelColor(head2, color2); // 'On' pixel at head2
	strip_S30.setPixelColor(tail2, 0);     // 'Off' pixel at tail2
	strip_S30.show();                     // Refresh strip

	//delay(20); /* Make it look like this core is doing something useful! */

	 if(++head2 >= NUMPIXELS) {         // Increment head0 index.  Off end of strip?
	    head2 = 0;                       //  Yes, reset head0 index to start
	    if((color2 >>= 8) == 0)          //  Next color0 (R->G->B) ... past blue now?
	      color2 = 0xFF0000;             //   Yes, reset to red
	  }
	  if(++tail2 >= NUMPIXELS) tail2 = 0; // Increment, reset tail0 index

	while(Htx_LockResource(&SerialASC.PortInUse) == Htx_RESOURCE_BUSY) { ; }

	SerialASC.print("Hello from Core 2\n\r");

	Htx_UnlockResource(&SerialASC.PortInUse);

}
