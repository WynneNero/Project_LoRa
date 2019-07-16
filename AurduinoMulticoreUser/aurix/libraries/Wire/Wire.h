/*
 * TwoWire.h - TWI/I2C library for Arduino Due
 * Copyright (c) 2011 Cristian Maglie <c.maglie@arduino.cc>
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef TwoWire_h
#define TwoWire_h

// Include Atmel CMSIS driver


#include "Stream.h"
#include "variant.h"
#undef DEC
#include "I2c/I2c/IfxI2c_I2c.h"



#define BUFFER_LENGTH 32
typedef enum { UsePins_6_7, UsePins_20_21, UsePins_SDA1_SCL1 } WirePinsType;

// For compatibility with original version
#define UsePins_16_17 UsePins_SDA1_SCL1


class TwoWire : public Stream {
public:
	TwoWire();
	void begin();
	void begin(uint8_t);
	void begin(int);
	void setClock(uint32_t);
	void beginTransmission(uint8_t);
	void beginTransmission(int);
	uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
	uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
	uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *, size_t);
	virtual int available(void);
	virtual int read(void);
	virtual int peek(void);
	virtual void flush(void);
	void onReceive(void(*)(int));
	void onRequest(void(*)(void));
	uint8_t findAddress(void);
	void setWirePins(WirePinsType _pins);
	void setWireBaudrate(uint32 _WireBaudrate);

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

	void onService(void);
	IfxI2c_I2c i2c;                      // i2c handle
	IfxI2c_I2c_Device i2cDev;
	uint8 read_Fifo_mem[256];
	Ifx_Fifo *read_Fifo;
	uint8 write_Fifo_mem[256];
	Ifx_Fifo *write_Fifo;
	IfxI2c_I2c_Config config;
	IfxI2c_I2c_deviceConfig i2cDeviceConfig;
	Ifx_CircularBuffer c_buf;
	WirePinsType WirePins;
	uint32 WireBaudrate;


private:



	// RX Buffer

	// Callback user functions
	void (*onRequestCallback)(void);
	void (*onReceiveCallback)(int);

	// Called before initialization
	void (*onBeginCallback)(void);

	// TWI instance
	//Twi *twi;

	// TWI state
	enum TwoWireStatus {
		UNINITIALIZED,
		MASTER_IDLE,
		MASTER_SEND,
		MASTER_RECV,
		SLAVE_IDLE,
		SLAVE_RECV,
		SLAVE_SEND
	};
	TwoWireStatus status;

	// TWI clock frequency
	static const uint32_t TWI_CLOCK = 100000;
	uint32_t twiClock;

	// Timeouts (
	static const uint32_t RECV_TIMEOUT = 100000;
	static const uint32_t XMIT_TIMEOUT = 100000;
};

#ifdef __cplusplus

extern TwoWire Wire; /* I2C interface */ /* Cannot be included in .C files */

#endif

#define DEC 10
#endif

