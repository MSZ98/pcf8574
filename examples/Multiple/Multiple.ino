#include <pcf8574.h>
#include <inttypes.h>

PCF8574 *ex[8];

// Example init and read/write 8 expanders
// Address 0x20 - A2, A1, A0 shorted to GND

void setup() {
	delay(200);
	Serial.begin(115200);

	int addr[8] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27};
	for(int i = 0;i < 8;i++) ex[i] = new PCF8574(addr[i]);

	// Read P4 of expander 6
	int state = digitalRead(*ex[6], 4);
	Serial.println(state, DEC);

	// Write 0 to P7 of expander 7
	digitalWrite(*ex[7], 7, 0);
	
}

void loop() {
	
}