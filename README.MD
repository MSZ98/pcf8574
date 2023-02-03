# PCF8574
Arduino library for PCF8574 IO expander module

## 1. Supported boards
Should work on most of the boards, tested on UNO, ESP32 and ESP8266

## 2. Usage
Everything is in the examples. Library is available in the Arduino Library Manager (Sketch -> Include Library -> Manage Libraries...).

### 2.1 Example write HIGH to P1
```
#include <pcf8574.h>

PCF8574 ex1(0x20);

void setup() {
	delay(200);
	pinMode(ex1, 1, OUTPUT);
	digitalWrite(ex1, 1, HIGH);
}

void loop() {}
```

### 2.2 Example read P0 state
```
#include <pcf8574.h>

PCF8574 ex1(0x20);

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
```

### 2.3 Example blink LED on P1
```
#include <pcf8574.h>

PCF8574 ex1(0x20);

void setup() {
	delay(200);
	pinMode(ex1, 1, OUTPUT);
}

void loop() {
	digitalToggle(ex1, 1);
	delay(500);
}
```

### 2.4 Example search for connected PCF8574
```
#include <pcf8574.h>

void setup() {
    delay(200);
    Serial.begin(115200);

    // SEARCH FOR PCF8574
    for(int i = 0;i < 8;i++) {
        int address = PCF8574::combinationToAddress(i, false);
        if(PCF8574(address).read() != -1) {
            Serial.print("Found PCF8574: addr = 0x");
            Serial.println(address, HEX);
        }
    }

    // SEARCH FOR PCF8574A
    for(int i = 0;i < 8;i++) {
        int address = PCF8574::combinationToAddress(i, true);
        if(PCF8574(address).read() != -1) {
            Serial.print("Found PCF8574A: addr = 0x");
            Serial.println(address, HEX);
        }
    }

    Serial.println("Search done. If you don't see anything, nothing was found.");

}

void loop() {}
```

## 3. How PCF8574 works?

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
 
## 4. Planned future features
 - attachInterrupt(function, pcf, pin, mode)
 - PCF8574 connection from any MCU pins 
