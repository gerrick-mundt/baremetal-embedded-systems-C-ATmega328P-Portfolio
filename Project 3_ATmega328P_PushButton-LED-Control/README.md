# Project Overview
The objective of this project was to expand my understanding of digital I/O by integrating both input and output functionality on the ATmega328P microcontroller, used in the Uno R3. While earlier projects focused solely on driving outputs, this project introduced a user input device — a pushbutton switch — to demonstrate real-time interaction between hardware input and output control at the register level.

The pushbutton was connected to PD7 (digital pin 7), which was configured as a digital input. With the internal pull-up resistor enabled, PD7 provided a stable logic HIGH when the button was released and transitioned to LOW when the button was pressed. The LED circuit was connected to PD4 (digital pin 4), which was configured as a digital output. Current flowed from PD4 through a resistor into the LED and returned to ground, allowing the microcontroller to directly control the LED state.

By monitoring the state of PD7 through the Port Input Pin Register (PIND) and writing output states to PD4 through the PORTD register, the program linked the button press to the LED in real time: pressing the button turned the LED on, while releasing it turned the LED off.

At a technical level, this project reinforced several key microcontroller concepts: 
* Configuring inputs and outputs using the DDR register
* Stabilizing input signals with internal pull-up resistors via the PORT register
* Polling input states through the PIN register. 

Together, these elements demonstrated how digital input can be translated directly into digital output, providing a foundation for more advanced interactive microcontroller applications.

# Software Description
## Software Used
* Development tool(s): VS Code
* Development Language: C
## Project Files
* List of .c and .h files: **[PushButton-LED-Control_main.c](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%203_ATmega328P_PushButton-LED-Control/Code/PushButton-LED-Control_main.c)**
* Source file Descriptions: Contains the source code responsible for configuring the ATmega328P's PD7 digital pin as an input, and setting PD4 as a digital voltage for the LED circuit.
* Makefile location: Project 3_ATmega328P_PushButton-LED-Control/Code
* Compiled outputs location: Project 3_ATmega328P_PushButton-LED-Control/Code

# Hardware
1. Microcontroller/board: ATmega328P/ Uno R3 (1)
2. USB cable (USB - Uno R3 compatible)
3. Breadboard (1)
4. Jumper wire (4)
5. Resistor (1)
6. LED (1)
7. SPST pushbutton (1)

![Circuit Diagram](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%203_ATmega328P_PushButton-LED-Control/Project%20Output/Circuit%20Diagram.png)

# Project Functionality
In this project, PD7 of the ATmega328P was configured as a digital input and connected to Arduino digital header pin 7. A pushbutton switch was wired between this input pin and ground. With the internal pull-up resistor enabled, PD7 normally reads HIGH when the button is not pressed and is pulled LOW when the button is pressed.

PD4 of the ATmega328P was configured as a digital output and connected to Arduino digital header pin 4. This pin was wired through a current-limiting resistor to an LED, which was then connected to ground to complete the LED circuit.

From a coding perspective, the Data Direction Register for Port D (DDRD) was configured to set PD7 as an input and PD4 as an output. The PORTD register was then used to enable the internal pull-up resistor on PD7, ensuring a defined logic level when the button is released. Inside an infinite while loop, the microcontroller continuously monitored the state of PD7 using the Port Input Pin Register (PIND). If PD7 read LOW (button pressed), the code set PD4 HIGH, driving current through the LED and turning it on. If PD7 read HIGH (button released), the code cleared PD4 to LOW, switching the LED off.

This setup allowed the pushbutton to act as a control signal for the LED, demonstrating how the ATmega328P can read a digital input and immediately translate it into a digital output action. The project highlights the interaction between the DDR, PORT, and PIN registers, reinforcing the principles of configuring inputs, outputs, and pull-up resistors at the register level.

# Outcomes
Did it work as intended: Yes
Challenges faced: Understanding how to properly place the SPST pushbutton on the breadboard
Lessons Learned: Learned how to set pins as inputs on the DDRx register, select the input to be a pull-up resistor option via PORTx register, and define what pin read the software should be looking for using the PINx register.

## Project Output
Pushbutton Not Pressed - 
![Pushbutton Not Pressed](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%203_ATmega328P_PushButton-LED-Control/Project%20Output/Pushbutton%20Not%20Pressed.jpeg)

Pushbutton Pressed - 
![Pushbutton Pressed](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%203_ATmega328P_PushButton-LED-Control/Project%20Output/Pushbutton%20Pressed.jpeg)

# Project Progression
* Skill level demonstrated: Beginner
* How it builds on previous projects: This project built on my earlier work with the ATmega328P, where I first learned to control a single GPIO pin to blink the onboard LED and then expanded to driving an external LED circuit. Unlike those earlier projects, this project integrated both input and output by connecting a pushbutton to PD7 and linking it to an LED on PD4. Pressing the button directly controlled the LED in real time, demonstrating interactive hardware behavior. This progression deepened my understanding of digital I/O and laid the foundation for more advanced embedded applications.
