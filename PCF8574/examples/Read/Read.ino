#include <PCF8574.h>

PCF8574 ex1(21, 22, 0x20);
//PCF8574 ex1(21, 22, PCF8574::combinationToAddress(0));

// Example read P0 state
// Button between GND and P0

void setup() {
	Serial.begin(9600);
	pinMode(ex1, 0, INPUT_PULLUP);
}

void loop() {
	Serial.printf("%d\n", digitalRead(ex1, 0));
	delay(500);
}