// Draw Boxes - Demonstrate drawRectangle and fillRectangle
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#include <stdint.h>

#define USE_DEFAULT_SPI

#ifdef USE_DEFAULT_SPI
	#include <TFTv2.h>  // Use default SPI channel on ICSP connector
#else
	#include <TFTv2_S1.h>  // Use SPI channel 2 on pin 10 - 13
#endif


//Basic Colours
#define RED		0xf800
#define GREEN	0x07e0
#define BLUE	0x001f
#define BLACK	0x0000
#define YELLOW	0xffe0
#define WHITE	0xffff


void setup()
{

	Tft.TFTinit();  // init TFT library

}



void printLogo(uint16 Xpos, uint16 Ypos);

uint16 ColourIndex = 0;
uint16 ColourSwap[8] = { RED, BLUE, GREEN, RED, YELLOW, BLUE, WHITE, BLACK };
uint8 cindex = 0;

void loop()
{


   for(int r=0;r<115;r=r+2)
   {

	   Tft.drawString("hitex",10, 10, 2, WHITE);
	   Tft.drawRectangle(77, 11, 60, 15, RED);
	   Tft.fillRectangle(77, 11, 60, 15, RED);

	   Tft.drawString("ShieldBuddyTC275 Cr0",0, 290, 2, (65535 - (ColourIndex += 10)));

	   //printLogo(10,100);

       Tft.drawCircle(119,160,r,ColourIndex += 10);//(r * 570));

       //Tft.drawVerticalLine(60,100,100,GREEN);

//       Tft.drawCircle(100, 100, 30,YELLOW);

//       Tft.drawCircle(100, 200, 40,GREEN);                 // center: (100, 200), r = 10 ,color : CYAN

       Tft.fillCircle(120, 100, 30,ColourSwap[cindex & 0x07]);                   //center: (200, 100), r = 30 ,color : RED

       Tft.fillCircle(120, 220, 30,ColourSwap[(cindex + 1) & 0x07]);

       cindex++;

   }


}


void printLogo(uint16 Xpos, uint16 Ypos)
{

	Tft.drawString("hitex",Xpos, Ypos, 2, WHITE);
	Tft.drawRectangle(Xpos + 67, Ypos + 1, 60, 15, RED);
	Tft.fillRectangle(Xpos + 67, Ypos + 1, 60, 15, RED);
}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:

	// Enable the LED pin
	pinMode(13, OUTPUT);

	SerialASC.begin(9600);

}

void loop1() {
  // put your main code core 1 here, to run repeatedly:


	/* Has core 2 put the pin low? */
    if(digitalRead(13) == LOW)
    {
    	delay(500);
    	digitalWrite(13,HIGH);
    	SerialASC.print("\n\rHello from Core1");  //  The pointer to the string seems to get set to NULL, causing a trap!
    }

}



/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:

	Serial1.begin(9600);

}

void loop2() {
  // put your main code core 2 here, to run repeatedly:


	/* Has core 1 put the pin high? */
    if(digitalRead(13) == HIGH)
    {
    	delay(500);
    	digitalWrite(13,LOW);
    	Serial1.print("\n\rHello from Core2");  //  The pointer to the string seems to get set to NULL, causing a trap!

    }


}



