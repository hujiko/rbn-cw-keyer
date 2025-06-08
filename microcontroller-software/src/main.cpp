#include <Arduino.h>
#include "CWKeyer.h"
#include "main.h"

// Time unit for a dot
const int dotLength = 90; // Define the length of a dot in milliseconds
// For 25 WPM use 52ms (measured on a YAESU FT-818nd)
// For 13 WPM use 90ms (measured on a YAESU FT-818nd)

// Define pins for short and long signals
const int shortPin = 2;  // Pin for short (dot)
const int longPin = 3;   // Pin for long (dash)

const int callSignPin = 13; // Pin for call sign toggle
const int speedPin = 16; // Pin for speed toggle

void setup() {
  // Initialize pins
  pinMode(shortPin, OUTPUT);
  pinMode(longPin, OUTPUT);
  pinMode(callSignPin, INPUT);
  pinMode(speedPin, INPUT);
}

void loop() {
  // Set transmission text based on the call sign switch state
  const char* text;
  if(digitalRead(callSignPin) == HIGH) {
    text = "TEST 2E0YSI 2E0YSI TEST 2E0YSI 2E0YSI TEST 2E0YSI 2E0YSI AR";
  } else {
    text = "TEST M7ISY M7ISY TEST M7ISY M7ISY TEST M7ISY M7ISY AR";
  }

  // Set the keyer speed based on the speed switch state
  // Currently, the librarz does not allow changing speed on the fly,
  // so we create a new instance of CWKeyer with the desired speed.
  int dotLength;
  if(digitalRead(speedPin) == HIGH) {
    dotLength = 90; // 13 WPM
  } else {
    dotLength = 52; // 25 WPM
  }
  CWKeyer keyer = CWKeyer(dotLength, shortPin, longPin);

  // Key the preprogrammed text in Morse code
  keyer.KeyText(text);

  // Pause before repeating the text
  delay(1000);
}
