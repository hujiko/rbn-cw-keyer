# RBN CW Keyer

This project involves using an Arduino to send predefined text as Morse code to reach the Reverse Beacon Network (RBN). The RBN is a network of radio stations worldwide that listen for Morse code signals and report the frequency, speed, and signal strength of the transmitted signals.

## Features

- Sends predefined text messages as Morse code using an Arduino.
- Configurable Morse code speed.
- Simple and easy-to-understand Arduino code.
- Easily extendable for custom text messages.

## Hardware Requirements

- Arduino Nano Board
- the CW keyer PCB or a breadboard installation
- 2 Optocouplers (e.g. EL817)
- 2 Resistors (~160 Ohm)
- (optional) 2 LEDs and matching resistors.

## Hardware setup

Solder the components to the PCB as instructed, or rebuild the circuit on a breadboard following the schematic in the `cw-keyer-hardware` directory. You need the free software `KiCAD` to open the schematic.

## Software setup (VSCode & PlatformIO)

Download the repository to your local machine and open VSCode. In the left side, there should be an icon looking like an alien-head. Click that to open the PlatformIO quick access menu. In there, click "Open", and in the then opened PlatformIO interface "Open Project". Navigate to the downloaded files and select the "microcontroller-software" subdirectory.

In the small bottom bar of PlatformIO you should now see a row of icons: A house, a checkmark, an arrow pointing right, a trash can, ...

Click the "Checkmark" icon. This will start compiling the source code. it should open a small terminal within PlatformIO and after 1-2 seconds, a green SUCCESS should indicate a successful compilation. Now connect your Arduino with a USB-Cable to your computer and in PlatformIO click the icon of an arrow pointing right. This should upload the project to your microcontroller. When doing that, you can either remove the microcontroller from the PCB, or leave it in. Both works completely fine.

Expect to see a green "SUCCESS" at least for "nanoatmega168". Don't worry if you see an error for "attiny85". As stated in the very beginning: We decided against using this microcontroller, as the financial benefit was not worth the limitations it brings.

## Change the text to be transmitted

in `microcontroller-software/src/main.cpp` change the `text` variable to what you want to be transmitted.

## Change the WPM speed

Currently the speed has to be set in milliseconds. For 25 WPM, use 52ms. For 13 WPM, use 90ms.
