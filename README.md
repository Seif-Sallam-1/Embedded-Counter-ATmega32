# Embedded-Counter-ATmega32
## 📦 ATmega32-Based Counter System

This project implements a digital counter using the **ATmega32** microcontroller. It uses:
- A **7-segment display** for real-time number output (0–7)
- **RGB LEDs** to reflect the current count in binary
- A **buzzer** to signal invalid actions
- **4 push buttons** for:
  - Increment
  - Decrement
  - Pause/Resume
  - Reset

> ✅ Debounced button handling  
> ✅ Visual and audio feedback  
> ✅ Compatible with ETA Burner for flashing  
> ✅ Includes Proteus simulation  
>  
Ideal for learning **embedded C**, I/O handling, digital logic, and real-time microcontroller interfacing.

---

## ✨ Features

- Increment/Decrement counter using push buttons
- Pause and resume functionality
- Binary representation using RGB LEDs
- 7-segment display output (0–7)
- Buzzer feedback when invalid actions occur (e.g., increment beyond 7)
- Full reset functionality (value reset + LED flash)

---

## 🧰 Requirements

- ATmega32 microcontroller
- 7-segment display
- 3 LEDs (Red, Green, Blue)
- 4 Push buttons (for INC, DEC, PAUSE, RESET)
- Buzzer
- **Proteus** for simulation and circuit design
- **ETA Burner** for uploading the HEX file to the physical board

---
## 📁 Folder Structure
Embedded-Counter-ATmega32/
│
├── code/ # Embedded C source code
│ └── Final_Project.c
│
├── Proteus_Simulation/ # Proteus simulation project files
│ └── *.pdsprj
│
├── tools/ # Burner tool and driver
│ ├── ETA_Burner_Installer.exe
│ └── ETA_Burner_Driver.inf
│
└── README.md

---

## 🔥 Flashing the Code to ATmega32

1. Compile the code using **AVR-GCC** or **Atmel Studio** to generate the HEX file.
2. Open **ETA Burner**, select your HEX file, and connect the board.
3. Burn the HEX to the ATmega32 chip.
4. Use the Proteus simulation to test, or upload to a real board.

---

## ⚠️ Important Setup & Installation Notes

### 🔐 Disable Antivirus or Windows Defender
> **❗ Before installing or using ETA Burner**, please:
- Temporarily **disable Windows Defender** and any antivirus software.
- The burner may be flagged as suspicious, but it is safe for this educational use.
- Re-enable protection after verifying installation is complete and working.

### 🧰 Recommended IDE
> ✅ Use an **older version of Eclipse IDE** (e.g., 2024-06 or earlier):
- Newer versions may not work well with **AVR Eclipse Plugin**.
- Ensure the **AVR-GCC toolchain** is correctly configured within Eclipse.

---

## 📷 Screenshots
<img width="1595" height="824" alt="image" src="https://github.com/user-attachments/assets/59edaa8b-b756-4894-885a-265155dc7a01" />

---

## 📜 License

MIT License or any open license of your choice.

---

## 🙌 Credits

Project by **Seif Emad Eldin Sallam** 
Embedded Systems Level 1
