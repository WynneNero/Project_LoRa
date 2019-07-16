/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/
//#pragma GCC optimize "-O0"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */

//uint8 NeoPixelBufferCore0_0[PIN_CORE0_0_LEDS * (((NEO_GRB >> 6) & 0b11) == ((NEO_GRB >> 4) & 0b11) ? 3:4)];

// Create Strip0 on core0, using pin 6
#define PIN_CORE0_0 		6
#define PIN_CORE0_0_LEDS  	60

// Parameter 1 = number of pixels in strip0
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(PIN_CORE0_0_LEDS, PIN_CORE0_0, NEO_GRB + NEO_KHZ800);

// Create Strip1 on core1, using pin 3
#define PIN_CORE1_0		 	3
#define PIN_CORE1_0_LEDS  	60

// Parameter 1 = number of pixels in strip1
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(PIN_CORE1_0_LEDS, PIN_CORE1_0, NEO_GRB + NEO_KHZ800);

// Create Strip2 on core2, using pin 4
#define PIN_CORE2_0		 	4
#define PIN_CORE2_0_LEDS  	60

// Parameter 1 = number of pixels in strip2
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(PIN_CORE2_0_LEDS, PIN_CORE2_0, NEO_GRB + NEO_KHZ800);

EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */




// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void colorWipe(uint32_t c, uint8_t wait) ;
void rainbow(uint8_t wait) ;
void rainbowCycle(uint8_t wait) ;
void theaterChase(uint32_t c, uint8_t wait) ;
void theaterChaseRainbow(uint8_t wait) ;
uint32_t Wheel(byte WheelPos) ;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip0.begin();
  strip0.show(); // Initialize all pixels to 'off'

}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip0.Color(255, 0, 0), 50); // Red
  colorWipe(strip0.Color(0, 255, 0), 50); // Green
  colorWipe(strip0.Color(0, 0, 255), 50); // Blue
//colorWipe(strip0.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  theaterChase(strip0.Color(127, 127, 127), 50); // White
  theaterChase(strip0.Color(127, 0, 0), 50); // Red
  theaterChase(strip0.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip0.numPixels(); i++) {
    strip0.setPixelColor(i, c);
    strip0.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip0.numPixels(); i++) {
      strip0.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip0.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip0.numPixels(); i++) {
      strip0.setPixelColor(i, Wheel(((i * 256 / strip0.numPixels()) + j) & 255));
    }
    strip0.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip0.numPixels(); i=i+3) {
        strip0.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip0.show();

      delay(wait);

      for (uint16_t i=0; i < strip0.numPixels(); i=i+3) {
        strip0.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip0.numPixels(); i=i+3) {
        strip0.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip0.show();

      delay(wait);

      for (uint16_t i=0; i < strip0.numPixels(); i=i+3) {
        strip0.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip0.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip0.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip0.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
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

void colorWipe1(uint32_t c, uint8_t wait) ;
void rainbow1(uint8_t wait) ;
void rainbowCycle1(uint8_t wait) ;
void theaterChase1(uint32_t c, uint8_t wait) ;
void theaterChaseRainbow1(uint8_t wait) ;
uint32_t Wheel1(byte WheelPos) ;


void setup1() {
  // put your setup code for core 1 here, to run once:

	delay(50);  // Insert small delay to prevent cores1 & 2 accessing start resources together.

	strip1.begin();
	strip1.show(); // Initialize all pixels to 'off'

}



void loop1() {
  // put your main code for core 1 here, to run repeatedly:

	  // Some example procedures showing how to display to the pixels:
	  colorWipe1(strip1.Color(255, 0, 0), 50); // Red
	  colorWipe1(strip1.Color(0, 255, 0), 50); // Green
	  colorWipe1(strip1.Color(0, 0, 255), 50); // Blue
	//colorWipe1(strip1.Color(0, 0, 0, 255), 50); // White RGBW
	  // Send a theater pixel chase in...
	  theaterChase1(strip1.Color(127, 127, 127), 50); // White
	  theaterChase1(strip1.Color(127, 0, 0), 50); // Red
	  theaterChase1(strip1.Color(0, 0, 127), 50); // Blue

	  rainbow1(20);
	  rainbowCycle1(20);
	  theaterChaseRainbow1(50);

}

// Fill the dots one after the other with a color
void colorWipe1(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(wait);
  }
}

void rainbow1(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip1.numPixels(); i++) {
    	strip1.setPixelColor(i, Wheel1((i+j) & 255));
    }
    strip1.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle1(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip1.numPixels(); i++) {
    	strip1.setPixelColor(i, Wheel1(((i * 256 / strip1.numPixels()) + j) & 255));
    }
    strip1.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase1(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
    	  strip1.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip1.show();

      delay(wait);

      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
    	  strip1.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow1(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
    	  strip1.setPixelColor(i+q, Wheel1( (i+j) % 255));    //turn every third pixel on
      }
      strip1.show();

      delay(wait);

      for (uint16_t i=0; i < strip1.numPixels(); i=i+3) {
    	  strip1.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel1(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
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

void colorWipe2(uint32_t c, uint8_t wait) ;
void rainbow2(uint8_t wait) ;
void rainbowCycle2(uint8_t wait) ;
void theaterChase2(uint32_t c, uint8_t wait) ;
void theaterChaseRainbow2(uint8_t wait) ;
uint32_t Wheel2(byte WheelPos) ;

void setup2() {
  // put your setup code for core 2 here, to run once:

	delay(51);  // Insert small delay to prevent cores1 & 2 accessing start resources together.

	strip2.begin();
	strip2.show(); // Initialize all pixels to 'off'

}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:

	  // Some example procedures showing how to display to the pixels:
	  colorWipe2(strip2.Color(255, 0, 0), 50); // Red
	  colorWipe2(strip2.Color(0, 255, 0), 50); // Green
	  colorWipe2(strip2.Color(0, 0, 255), 50); // Blue
	//colorWipe2(strip2.Color(0, 0, 0, 255), 50); // White RGBW
	  // Send a theater pixel chase in...
	  theaterChase2(strip2.Color(127, 127, 127), 50); // White
	  theaterChase2(strip2.Color(127, 0, 0), 50); // Red
	  theaterChase2(strip2.Color(0, 0, 127), 50); // Blue

	  rainbow2(20);
	  rainbowCycle2(20);
	  theaterChaseRainbow2(50);

}


// Fill the dots one after the other with a color
void colorWipe2(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip2.numPixels(); i++) {
    strip2.setPixelColor(i, c);
    strip2.show();
    delay(wait);
  }
}

void rainbow2(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip2.numPixels(); i++) {
    	strip2.setPixelColor(i, Wheel2((i+j) & 255));
    }
    strip2.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle2(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip2.numPixels(); i++) {
    	strip2.setPixelColor(i, Wheel2(((i * 256 / strip2.numPixels()) + j) & 255));
    }
    strip2.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase2(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip2.numPixels(); i=i+3) {
    	  strip2.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip2.show();

      delay(wait);

      for (uint16_t i=0; i < strip2.numPixels(); i=i+3) {
    	  strip2.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow2(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip2.numPixels(); i=i+3) {
    	  strip2.setPixelColor(i+q, Wheel2( (i+j) % 255));    //turn every third pixel on
      }
      strip2.show();

      delay(wait);

      for (uint16_t i=0; i < strip2.numPixels(); i=i+3) {
    	  strip2.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel2(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
