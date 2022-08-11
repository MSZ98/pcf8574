/*
    pcf8574.cpp
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

#include "pcf8574.h"

/* PCF8574 does not support different pin modes. Input mode is just a HIGH state (high state is always pull-up). It also does not support pull-down. */
void pinMode(PCF8574 &expander, int pin, int mode) {
	if(mode != OUTPUT) digitalWrite(expander, pin, HIGH);
}

int digitalWrite(PCF8574 &expander, int pin, int value) {
	int reg =    expander.getReg();
	int result = expander.write(value ? reg | (1 << pin) : reg &~ (1 << pin));
	return result;
}

int digitalRead(PCF8574 &expander, int pin) {
	return (expander.read() & (1 << pin)) ? HIGH : LOW;
}

int digitalToggle(PCF8574 &expander, int pin) {
	int reg =    expander.getReg();
	int result = expander.write(reg ^ (1 << pin));
	return result;
}

int PCF8574::combinationToAddress(int A2_A1_A0, bool version_A) {
	if(A2_A1_A0 < 0 || A2_A1_A0 > 7) return -1;
	if(version_A) return 0x38 + A2_A1_A0;
	return 0x20 + A2_A1_A0;
}
