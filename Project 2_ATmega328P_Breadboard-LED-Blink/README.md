# Project Overview
The objective of this project was to further develop hands-on experience with the ATmega328P microcontroller architecture. Specifically, it focused on configuring digital GPIO pins using the Data Direction Registers (DDR) and implementing basic register-level control to toggle an output pin. Beyond understanding embedded concepts, the project also provided practical experience in using the microcontroller’s output voltage to power a simple circuit consisting of two LEDs and two resistors.

# Software Description
## Software Used
* Development tool(s): VS Code
* Development Language: C

## Project Files
* List of .c and .h files: **[breadBoardLED_main.c](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%202_ATmega328P_Breadboard-LED-Blink/Code/breadBoardLED_main.c)**
* Source file Descriptions: Contains the source code responsible for configuring the ATmega328P's PD7 pin as an output using the Data Direction Register (DDR) and toggling its state in a timed loop.
*  Makefile location: Project 2_ATmega328P_Breadboard-LED-Blink/Makefile
* Compiled outputs location: Project 2_ATmega328P_Breadboard-LED-Blink/main.hex

# Hardware
1. Microcontroller/board: ATmega328P/ Uno R3 (1)
2. USB cable (USB - Uno R3 compatible)
3. Breadboard (1)
4. Jumper wire (2)
5. Resistor (2)
6. LED (2)

![Circuit Diagram](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%202_ATmega328P_Breadboard-LED-Blink/Project%20Output/CircuitDiagram_Breadboard-LED-Blink.png)

# Project Functionality
In this project, PD7 of the ATmega328P was configured as a digital output and connected to Arduino digital header pin 7. This pin supplied voltage to a jumper wire on a breadboard, which routed current through a resistor to power a colored LED. The LED was then connected through another resistor to a second LED, completing the series. The second LED was connected to the ground rail on the breadboard, which returned to the Arduino ground pin via another jumper wire. This setup created a complete circuit, allowing current to flow and illuminate the LEDs.

From a coding perspective, this was implemented by configuring the Data Direction Register for Port D (DDRD) to set PD7 as an output. An infinite while loop was then used to create a continuous cycle: a bitmask was applied to set PD7 high, turning on the LED, followed by a 1-second delay using the <util/delay.h> function. The pin was then set low using a bitmask to turn off the LED, followed by another 1-second delay. This loop repeated indefinitely, creating a continuous LED blink.

# Outcomes
* Did it work as intended: Yes
* Challenges faced: Making sure the circuit was properly aligned and the resistors provided the proper resistance to that the LEDs did not overheat and burn out.
* Lessons Learned: nothing new from a software perspective.
* Project Output - 

![Project Output](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%202_ATmega328P_Breadboard-LED-Blink/Project%20Output/Full%20Circuit%20Build.jpg)

# Project Progression
* Skill level demonstrated: Beginner
* How it builds on previous projects: Built on my previous project by reusing the same logic but providing a more complex real world usage for the voltage that was supplied. Also, I worked with a different pin to familiarize myself with the MCU GPIO configurations further on the ATmega328P.
