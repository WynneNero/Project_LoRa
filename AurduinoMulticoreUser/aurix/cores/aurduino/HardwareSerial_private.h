/*
  HardwareSerial_private.h - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
*/

//#include "wiring_private.h"

// this next line disables the entire HardwareSerial.cpp, 
// this is so I can support Attiny series and any other chip without a uart
#if defined(HAVE_HWSERIAL0) || defined(HAVE_HWSERIAL1) || defined(HAVE_HWSERIAL2) || defined(HAVE_HWSERIAL3)

// Ensure that the various bit positions we use are available with a 0
// postfix, so we can always use the values for UART0 for all UARTs. The
// alternative, passing the various values for each UART to the
// HardwareSerial constructor also works, but makes the code bigger and
// slower.




// Constructors ////////////////////////////////////////////////////////////////



HardwareSerial::HardwareSerial(volatile Ifx_ASCLIN *MODULE_ASCLINx, IfxAsclin_Asc *asc, IfxAsclin_Asc_Pins *pins,
		unsigned short ASCLIN_TX_IntPriority,
		unsigned short ASCLIN_RX_IntPriority,
		unsigned short ASCLIN_Err_IntPriority) :

  	_MODULE_ASCLINx(MODULE_ASCLINx),
  	_asc(asc),
  	_pins(pins),
  	_ASCLIN_TX_IntPriority(ASCLIN_TX_IntPriority),
  	_ASCLIN_RX_IntPriority(ASCLIN_RX_IntPriority),
  	_ASCLIN_Err_IntPriority(ASCLIN_Err_IntPriority)

{
}

// Actual interrupt handlers //////////////////////////////////////////////////////////////



#endif // whole file
