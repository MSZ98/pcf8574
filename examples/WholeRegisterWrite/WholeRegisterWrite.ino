#include <pcf8574.h>

PCF8574 ex1(0x20);

// Example write whole PCF8574 register
// Address 0x20 - A2, A1, A0 shorted to GND
// pinMode is not needed

void setup() {
	delay(200);
	ex1.write(0xAA);
}

void loop() {

}