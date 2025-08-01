# Embedded-Counter-ATmega32
ATmega32-Based Counter System
This project implements a digital counter using the ATmega32 microcontroller. The system includes:
7-segment display for real-time number output (0–7)
RGB LEDs to reflect binary value visually
Buzzer alerts for invalid operations
Four push buttons to increment, decrement, pause/resume, and reset the count
✅ Debounced button handling
✅ Visual and audio feedback
✅ Compatible with ETA Burner for flashing
✅ Includes Proteus simulation
Ideal for learning embedded C, I/O handling, and real-time interfacing with microcontrollers.

## Features
- Increment/Decrement using push buttons
- Pause/Unpause toggle
- Visual output using RGB LEDs
- 7-segment numeric display
- Sound and light alerts for boundaries and reset

## Requirements
- ATmega32 microcontroller
- 7-segment display
- 3 LEDs (R, G, B)
- 4 push buttons
- Buzzer
- Proteus for simulation
- ETA Burner for uploading the hex file

## Folder Structure
- `/src`: Contains the embedded C code
- `/proteus`: Contains Proteus simulation files
- `/tools`: Contains ETA Burner installer and driver

## Flashing the Code
1. Compile the code using **AVR-GCC** or **Atmel Studio**.
2. Burn the HEX file using **ETA Burner**.
3. Connect the board as per the Proteus circuit.
