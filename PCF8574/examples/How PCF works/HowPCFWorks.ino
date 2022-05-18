#include "PCF8574.h"

PCF8574 ex1(21, 22, 0x20);
//PCF8574 ex1(21, 22, PCF8574::combinationToAddress(0));

// PCF8574:
// Has only one 8-bit register to write
// So, the pin can be in two states - connected to GND or (100uA) pull-up'ed

// If register bit corresponding to IO is 0, pin is connected to GND
// If register bit corresponding to IO is 1, pin has 100uA pull-up
// This pull-up is used for both input-pullup and output high

// When pin changes state from 0 to 1 it's connected to VCC for a moment
// This "moment" is equal to I2C ACK time

// It uses two I2C addresses - one for write and second for read
// If "write" address is 0x20, read will be 0x21 (incremented)

// Addresses are set with onboard jumpers, but combination is not the address
// For PCF8574, first write address is 0x20 and last write address is 0x27
// For PCF8574A, first write address is 0x38 and last write address is 0x3F

// You can make external pull-down resistor if you need

// Read datasheet for more precise description

void setup() {
	digitalWrite(ex1, 1, HIGH);
}

void loop() {

}