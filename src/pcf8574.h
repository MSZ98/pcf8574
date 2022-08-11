/*
    pcf8574.h
    Version 1.0.3
    Created 18.05.2022
    Author: MSZ98 (github.com/MSZ98)

    Copyright (C) 2022 MSZ98

    This file is part of the Arduino pcf8574.h library.

    The pcf8574.h library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
    
    The Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
    See the GNU Lesser General Public License for more details.
    
    You should have received a copy of the GNU Lesser General Public
    License along with the GNU C Library; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PCF8574_H
#define PCF8574_H

#include <Arduino.h>
#include <Wire.h>

#define PCF8574_CLOCK 100000

class PCF8574 {

	private:
	int address, reg = 255;
	TwoWire *wire;
	
	public:
	PCF8574(TwoWire &wire, int address) {
		this->address = address;
		this->wire = &wire;
		Wire.begin();
		Wire.setClock(PCF8574_CLOCK);
	}
	PCF8574(int address) {
		this->address = address;
		this->wire = &Wire;
		Wire.begin();
		Wire.setClock(PCF8574_CLOCK);
	}
	#ifdef STICKBREAKER
	PCF8574(int SDA, int SCL, int address) {
		this->address = address;
		wire = &Wire;
		Wire.begin(SDA, SCL);
		Wire.setClock(PCF8574_CLOCK);
	}
	#endif

	int write(int reg) {
		wire->beginTransmission(address);
		wire->write(reg);
		int result = wire->endTransmission();
		if(result == 0) this->reg = reg;
		return result;
	}

	int read() {
		int result = wire->requestFrom(address, 1);
		if(result == 0) return -1;
		return wire->read();
	}

	int getReg() {
		return reg;
	}

	static int combinationToAddress(int A2_A1_A0, bool version_A);

};

void pinMode(PCF8574&, int, int);
int  digitalWrite(PCF8574&, int, int);
int  digitalRead(PCF8574&, int);
int  digitalToggle(PCF8574&, int);

#endif /* PCF8574_H */
