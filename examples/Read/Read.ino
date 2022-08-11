#include <pcf8574.h>

PCF8574 ex1(0x20);

// Example read P0 state
// Button between GND and P0
// Address 0x20 - A2, A1, A0 shorted to GND

// Warning! PCF8574 supports only input pullup
// Shorting PCF pin to VCC can cause PCF chip damage.

void setup() {
	delay(200);
	Serial.begin(115200);
	pinMode(ex1, 0, INPUT_PULLUP);
}

void loop() {
	int state = digitalRead(ex1, 0);
	if(state == -1) Serial.println("PCF8574 not detected");
	Serial.println(String(state));
	delay(500);
}