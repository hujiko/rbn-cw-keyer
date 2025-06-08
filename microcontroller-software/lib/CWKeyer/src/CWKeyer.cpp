#include "CWKeyer.h"

// Morse code mapping for uppercase letters, space, and numbers
const char* morseCode[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--..", // Z
  "-----", // 0
  ".----",  // 1
  "..---",  // 2
  "...--",  // 3
  "....-",  // 4
  ".....",  // 5
  "-....",  // 6
  "--...",  // 7
  "---..",  // 8
  "----."   // 9
};

CWKeyer::CWKeyer(int dotLength, int shortPin, int longPin)
: dotLength(dotLength), shortPin(shortPin), longPin(longPin) {

  // Calculate timing units
  dashLength = dotLength * 3;         // Dash is 3 time units
  symbolSpace = dotLength;            // Space between symbols within the same letter
  letterSpace = dotLength * 3;        // Space between letters
  wordSpace = dotLength * 12;          // Space between words

  pinMode(shortPin, OUTPUT);  // Pin for short (dot)
  pinMode(longPin, OUTPUT);   // Pin for long (dash)
}

const char* CWKeyer::getMorseChar(char c) {
  if (c >= 'A' && c <= 'Z') {
    return morseCode[c - 'A'];
  } else if (c >= '0' && c <= '9') {
    return morseCode[26 + (c - '0')];
  } else if (c == ' ') {
    return ""; // space
  }
  return ""; // return empty for unsupported characters
}

void CWKeyer::KeyText(const char* text) {
  for (int i = 0; text[i] != '\0'; i++) {
    const char* morse = getMorseChar(text[i]);

    for (int j = 0; morse[j] != '\0'; j++) {
      if (morse[j] == '.') {
        digitalWrite(shortPin, HIGH);
        delay(dotLength);
        digitalWrite(shortPin, LOW);
      } else if (morse[j] == '-') {
        digitalWrite(longPin, HIGH);
        delay(dashLength);
        digitalWrite(longPin, LOW);
      }
      delay(symbolSpace);
    }

    if (text[i + 1] != '\0') {
      delay(letterSpace);
    }
  }

  // Gap between words
  delay(wordSpace);
}
