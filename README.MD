# PCF8574
Arduino library for PCF8574 IO expander module

## Supported boards
Should work on most of the boards, tested on UNO and ESP32DevKitV1

## Usage
### Example write HIGH to P1
```
#include <pcf8574.h>

PCF8574 ex1(0x20);
//PCF8574 ex1(21, 22, 0x20); // FOR ESP32

void setup() {
	pinMode(ex1, 1, OUTPUT);
	digitalWrite(ex1, 1, HIGH);
}

void loop() {

}
```

### Example read P0 state
```
#include <pcf8574.h>

PCF8574 ex1(0x20);
//PCF8574 ex1(21, 22, 0x20); // FOR ESP32

void setup() {
	Serial.begin(9600);
	pinMode(ex1, 0, INPUT_PULLUP);
}

void loop() {
	Serial.printf("%d\n", digitalRead(ex1, 0));
	delay(500);
}
```

### Example blink LED on P1
```
#include <pcf8574.h>

PCF8574 ex1(0x20);
//PCF8574 ex1(21, 22, 0x20); // FOR ESP32

// LED diode between GND and P1

void setup() {
	pinMode(ex1, 1, OUTPUT);
}

void loop() {
	digitalToggle(ex1, 1);
	delay(500);
}
```

### Constructor
Constructor is different for Arduino AVR Boards and ESP32 due to Wire.h library implementation differences.
Note: address is the PCF8574 module address you set on the expander's board.
#### Adruino AVR Boards</br>
PCF8574(int address)</br>
PCF8574(TwoWire &wire, int address)</br>
#### ESP32
PCF8574(int SDA, int SCL, int address)</br>
PCF8574(TwoWire &wire, int address)</br>

</br>Note: you have to call setPins(SDA, SCL) before calling TwoWire constructor on ESP32</br>

### Functions

void pinMode      (PCF8574 &expander, int pin, int mode)</br>
void digitalWrite (PCF8574 &expander, int pin, int value)</br>
int  digitalRead  (PCF8574 &expander, int pin)</br>
void digitalToggle(PCF8574 &expander, int pin)</br></br>
int  PCF8574::combinationToAddress(int A2_A1_A0, bool version_A)</br>

### Including library

1. Download release
2. In Arduino IDE ... Sketch -> Include library -> Add .ZIP Library...
3. #include <pcf8574.h>

<\br><\br>OR<\br><\br>
1. In Arduino IDE ... Sketch -> Include library -> Manage Libraries...
2. Find and install pcf8574 by MSZ98
3. #include <pcf8574.h>

## About
This library allows microcontroller to use PCF8574 io expander module. If defines new class PCF8574 and special digitalWrite() as well as digitalRead(), which need also an object of type PCF8574. In my opinion it's the simplest library for this chip.

## How PCF8574 works?

 **PCF8574:**
 - Has only one 8-bit register to write
 - So, the pin can be in two states - connected to GND or (100uA) pull-up'ed
---
 - If register bit corresponding to IO is 0, pin is connected to GND
 - If register bit corresponding to IO is 1, pin has 100uA pull-up
 - This pull-up is used for both input-pullup and output high
---
 - When pin changes state from 0 to 1 it's connected to VCC for a moment
 - This "moment" is equal to I2C ACK time
---
 - It uses two I2C addresses - one for write and second for read
 - If "write" address is 0x20, read will be 0x21 (incremented)
---
 - Addresses are set with onboard jumpers, but combination is not the address
 - For PCF8574, first write address is 0x20 and last write address is 0x27
 - For PCF8574A, first write address is 0x38 and last write address is 0x3F
 
 
 
 
 
 
 
 
