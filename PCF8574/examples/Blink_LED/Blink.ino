#include "PCF8574.h"

PCF8574 ex1(21, 22, 0x20);
//PCF8574 ex1(21, 22, PCF8574::combinationToAddress(0));

// LED DIODE CONNECTED TO PIN 0 OF PCF8574

//          R      LED
// GND ----====----|>|---- P0
// R = 2.2k

void setup() {
	pinMode(ex1, 0, OUTPUT);
}

void loop() {
	digitalToggle(ex1, 0);
	delay(500);
}