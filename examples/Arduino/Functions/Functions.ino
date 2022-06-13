#include <pcf8574.h>

PCF8574 ex1(0x20);
//PCF8574 ex1(PCF8574::combinationToAddress(0));

/** Classic Arduino IDE doesn't have docs preview, 
 ** so here are the most important functions.
 * 
 * void pinMode(PCF8574&, int, int);
 * Too simple to describe, but remember,
 * PCF doesn't have pullDown.
 * Also, output high is through pull-up resistor.
 * Read PCF datasheet for more info.
 * 
 * int digitalWrite(PCF8574&, int, int);
 * Look at the return type. It returns info
 * about what happened during I2C communication.
 * According to Wire.endTransmission() docs:
 * 0: success.
 * 1: data too long to fit in transmit buffer.
 * 2: received NACK on transmit of address.
 * 3: received NACK on transmit of data.
 * 4: other error.
 * 5: timeout
 * So, if you ran Blink example and it doesn't work,
 * Serial.println(result) of this function and if
 * it's 2, most likely problem is the wrong address.
 * This file is example digitalWrite() return test.
 * 
 * int digitalRead(PCF8574&, int);
 * Too simple to describe.
 * 
 * int digitalToggle(PCF8574&, int);
 * This is much like digitalWrite(), but instead
 * of writing specific value, toggles it.
 * 
 * int PCF8574::combinationToAddress(int A2_A1_A0, bool version_A)
 * This takes juper or onboard PCF address switches combination
 * as a first parameter and true if you have PCF8574A.
 * Returns address calculated in accordance with PCF datasheet,
 * which you can put into constructor to init the library.
*/

int result = -1;

void setup() {
	Serial.begin(9600);
	result = digitalWrite(ex1, 1, HIGH);
}

void loop() {
	delay(1000);
	Serial.println(result);
}