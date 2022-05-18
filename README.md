# PCF8574
Arduino library for PCF8574 IO expander module

## Supported boards
Should work on most of the boards, tested on UNO and ESP32DevKitV1

## Usage
### Example write HIGH to P0
```
#include "PCF8574.h"

PCF8574 ex1(21, 22, 0x20);
//PCF8574 ex1(21, 22, PCF8574::combinationToAddress(0));

void setup() {
	pinMode(ex1, 0, OUTPUT);
	digitalWrite(ex1, 0, HIGH);
}

void loop() {

}
```

### Example read P0 state
```
#include "PCF8574.h"

PCF8574 ex1(21, 22, 0x20);
//PCF8574 ex1(21, 22, PCF8574::combinationToAddress(0));

void setup() {
	Serial.begin(9600);
	pinMode(ex1, 0, INPUT_PULLUP);
}

void loop() {
	Serial.printf("%d\n", digitalRead(ex1, 0));
	delay(500);
}
```

### Constructor

PCF8574(int SDA, int SCL, int address)</br>

### Functions

void pinMode(PCF8574 &expander, int pin, int mode)</br></br>
void digitalWrite(PCF8574 &expander, int pin, int value)</br></br>
int digitalRead(PCF8574 &expander, int pin)</br></br>
void digitalToggle(PCF8574 &expander, int pin)</br></br>
int PCF8574::combinationToAddress(int A2_A1_A0, bool version_A)</br></br>

### Including library

1. Download ![zip](https://github.com/MSZ98/PCF8574/blob/c721a34f64b1c87be76e3dafd22e044b77ca8cd9/PCF8574.zip)
2. In Arduino IDE ... Sketch -> Include library -> Add .ZIP Library...
3. #include <PCF8574.h>

## About
This library allows microcontroller to use PCF8574 io expander module. If defines new class PCF8574 and special digitalWrite() as well as digitalRead(), which need also an object of type PCF8574. In my opinion it's the simplest library for this chip.
 
 
 
 
 
 
 
 
