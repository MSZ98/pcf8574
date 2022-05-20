/**
 * PCF8574.cpp - Library for PCF8574 io expander module
 * Created by MSZ, May 18, 2022.
 * Released into the public domain.
*/

#ifndef PCF8574_H
#define PCF8574_H

#include <Wire.h>

class PCF8574 {

	private:
	int address, reg = 255;
	
	public:
	PCF8574(int SDA, int SCL, int address) {
		this->address = address;
		Wire.begin(SDA, SCL);
		Wire.setClock(100000);
	}

	int write(int reg) {
		Wire.beginTransmission(address);
		Wire.write(reg);
		int result = Wire.endTransmission();
		if(result == 0) this->reg = reg;
		return result;
	}

	int read() {
		int result = Wire.requestFrom(address, 1);
		int reg = Wire.read();
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
void digitalToggle(PCF8574&, int);

#endif /* PCF8574_H */
