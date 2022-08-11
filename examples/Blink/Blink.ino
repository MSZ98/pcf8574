#include <pcf8574.h>

PCF8574 ex1(0x20);

// Example blink diode at P1
// LED diode between GND and P1
// Address 0x20 - A2, A1, A0 shorted to GND

void setup() {
	delay(200);
	pinMode(ex1, 1, OUTPUT);
}

void loop() {
	digitalToggle(ex1, 1);
	delay(500);
}