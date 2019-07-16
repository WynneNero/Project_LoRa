
#ifndef _NEOPIXEL_CFG_
#define _NEOPIXEL_CFG_

/*** User Settings ***/

/* WS2812B timings */
/* Units of time are 10ns */
#define NEOPIXEL_ZERO_DR		(35u)  /* 0.35us */
#define NEOPIXEL_ONE_DR		    (90u)  /* 0.9us  */
#define NEOPIXEL_LOW_DR		    (0u)   /* Low for reset */
#define NEOPIXEL_RESET_TIMEOUT  (00u)  /* 50us low for reset, in units of 1.25us */


#endif _NEOPIXEL_CFG_
