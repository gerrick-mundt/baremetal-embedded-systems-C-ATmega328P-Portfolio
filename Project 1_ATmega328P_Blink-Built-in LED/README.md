# Project Overview
The objective of this project is to gain hands-on familiarity with the ATmega328P microcontroller architecture, learn how to configure digital GPIO pins using the Data Direction Registers (DDR), and implement basic register-level control to toggle an output pin. Specifically, it aims to control the PB5 pin to blink the built-in LED on the Arduino Uno R3, providing foundational experience in low-level embedded programming.

# Software Description
## Software Used
* Development tool(s): VS Code
* Development Language: C
* Included Headers: 1) <avr/io.h>, 2) <util/delay.h>

## Project Files
* List of .c and .h files: **[blinkLED_main.c](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%201_ATmega328P_Blink-Built-in%20LED/blinkLED_main.c)**
* Source file Descriptions: Contains the source code responsible for configuring the ATmega328P's PB5 pin as an output using the Data Direction Register (DDR) and toggling its state in a timed loop.

# Hardware
1. Microcontroller/board: ATmega328P/ Uno R3
2. USB cable (USB - Uno R3 compatible)

# Project Functionality
This project demonstrates basic GPIO control on the ATmega328P by toggling the built-in LED connected to PB5. The microcontroller’s Data Direction Register (DDR) is configured to set PB5 as an output, and the program alternates the pin between high and low states with a one-second delay, producing a continuous blinking effect on the onboard LED. This simple project provides hands-on experience with register-level programming and microcontroller pin manipulation.

# Outcomes
* Did it work as intended: Yes
* Challenges faced: There was no real challenges faced on this one, mostly learning key embedded concepts for the first time.
* Lessons Learned: 

1. When using non-standard or custom header files in VS Code, you need to update the configuration file to include the locations of those headers. If this isn’t done, IntelliSense may mark the headers as incorrect, although compilation might still succeed. 
2. To flash a .hex file to an ATmega328P using the Arduino bootloader, the avrdude command-line tool is used. Key components of the command that is needed to do this includes:

-c arduino → Tells avrdude to use the Arduino bootloader protocol.
-p m328p → Specifies the target microcontroller as the ATmega328P.
-P /dev/tty.usbmodem14101 → The USB port where your Arduino Uno is connected.
-b 115200 → The baud rate (symbols per second) for communication with the bootloader.
-U flash:w:blink.hex → Writes the compiled .hex file (e.g., blink.hex) to the flash memory of the Uno.

This ensures your program is correctly uploaded to the microcontroller.

# Project Progression
* Skill level demonstrated: Beginner
* How it builds on previous projects: It is the first project that I have done thus far.

