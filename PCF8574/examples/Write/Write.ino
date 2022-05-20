#include <PCF8574.h>

PCF8574 ex1(21, 22, 0x20);
//PCF8574 ex1(21, 22, PCF8574::combinationToAddress(0));

// Example write HIGH to P1
// LED diode between GND and P1

void setup() {
	pinMode(ex1, 1, OUTPUT);
	digitalWrite(ex1, 1, HIGH);
}

void loop() {

}