#include <pcf8574.h>

PCF8574 ex1(0x20);

// Example read whole PCF8574 register
// Address 0x20 - A2, A1, A0 shorted to GND

// Warning! PCF8574 supports only input pullup
// Shorting PCF pin to VCC can cause PCF chip damage.

void setup() {
	delay(200);
	Serial.begin(115200);
	pinMode(ex1, 0, INPUT_PULLUP);
}

void loop() {
	int reg = ex1.read();
    if(reg == -1) Serial.println("PCF8574 not detected");
	Serial.println(reg, BIN);
	delay(500);
}