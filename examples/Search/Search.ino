#include <pcf8574.h>

// Example search for PCF8574

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

void loop() {

}