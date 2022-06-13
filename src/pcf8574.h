/**
 * pcf8574.cpp - Library for PCF8574 io expander module
 * Created by MSZ, May 18, 2022.
 * Released into the public domain.
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
		int reg = wire->read();
		return reg;
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
