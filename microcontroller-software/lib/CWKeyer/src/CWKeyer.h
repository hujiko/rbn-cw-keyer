#ifndef CWKEYER_H
#define CWKEYER_H

#include <Arduino.h>

extern const char* morseCode[];

class CWKeyer {
public:
    CWKeyer(int dotLength, int shortPin, int longPin);

    void KeyText(const char* text);

private:
    int dotLength;
    int dashLength;
    int symbolSpace;
    int letterSpace;
    int wordSpace;
    
    int shortPin;
    int longPin;

    const char* getMorseChar(char c);
};

#endif
