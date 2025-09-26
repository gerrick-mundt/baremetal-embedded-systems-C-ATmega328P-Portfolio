# New Definitions
## Interrupt  
An **interrupt** is a hardware signal that tells the microcontroller to pause normal execution and immediately handle a specific event. 

The sequence of how an interrupt works on the ATmega328P:  

1. **Normal Program Execution** – The CPU executes instructions in `main()`.  
2. **Interrupt Event Occurs** – Example: the button connected to **PD2 (INT0)** is pressed.  
   - PD2 is configured as an **input** (`DDRD &= ~(1 << PD2)`), with its **internal pull-up resistor** enabled (`PORTD |= (1 << PD2)`).  
   - PD2 is internally mapped to **INT0**, which corresponds to **bit 0** of the **External Interrupt Mask Register (EIMSK)**. Setting this bit enables PD2 to generate interrupts.  
   - The **External Interrupt Control Register A (EICRA)** defines the trigger condition. In this project, INT0 is set to **falling edge**, meaning the interrupt fires when PD2 transitions from HIGH → LOW (button press).  

3. **Interrupt Request (IRQ)** – The PD2 pin transition signals the interrupt controller.  

4. **Program Pauses** – The CPU saves its current state (program counter, registers).  

5. **Interrupt Service Routine (ISR)** – The CPU jumps to the ISR defined for `INT0_vect`. In this project, the ISR toggles the LED on PD4.  

6. **ISR Completes** – Once finished, the CPU restores its state and resumes program execution exactly where it left off.  


## External Interrupt Mask Register (EIMSK)  
The **External Interrupt Mask Register (EIMSK)** controls whether an external interrupt channel is enabled or ignored (“masked”).  

- Setting **bit 0 (INT0)** enables the external interrupt on **PD2**, which is internally mapped to **INT0**.  
- Clearing the bit disables the interrupt, meaning activity on PD2 will not generate an interrupt request.  

**In short:** EIMSK allows PD2 (via INT0) to trigger interrupts when enabled.  


## External Interrupt Control Register A (EICRA)  
The **External Interrupt Control Register A (EICRA)** defines *how* an external interrupt is triggered, while the **EIMSK** register acts as the ON/OFF switch.  

For **INT0 (PD2)**, EICRA uses the bit pair **ISC01** and **ISC00** to determine the trigger condition:  

| ISC01 | ISC00 | Trigger Condition                          |
|-------|-------|---------------------------------------------|
| 0     | 0     | **Low level** – interrupt fires as long as PD2 is LOW |
| 0     | 1     | **Any logical change** – HIGH ↔ LOW or LOW ↔ HIGH |
| 1     | 0     | **Falling edge** – HIGH → LOW transition    |
| 1     | 1     | **Rising edge** – LOW → HIGH transition     |

**In this project:**  
- **ISC01 = 1** and **ISC00 = 0**, which configures INT0 to fire on the **falling edge** (button press, HIGH → LOW).  

## Interrupt Service Routine (ISR)  
An **Interrupt Service Routine (ISR)** is a special function that runs automatically when an interrupt occurs.  

- You never call an ISR directly — the microcontroller jumps to it whenever the hardware signals that an event has happened.  
- After the ISR finishes, the CPU returns to exactly what it was doing before the interrupt.  
- ISRs are declared using the `ISR()` macro from `<avr/interrupt.h>`.  
- The argument (e.g., `INT0_vect`) tells the compiler which interrupt the routine handles.  

# Project Overview
The objective of this project was to build on my previous experience with GPIO input and output by introducing interrupt-driven input handling on the ATmega328P microcontroller. While my previous project relied on polling (continuously checking if an input change had occurred using a while loop) to monitor the state of the pushbutton, this implementation replaced continuous input checking with an external interrupt (INT0), demonstrating the efficiency and responsiveness of event-driven programming. 

In this set up, the SPST pushbutton was connected to PD2 (digital pin 2), which is internally mapped to the INT0 external interrupt channel. The pin was configured as an input with the internal pull-up resistor enabled, ensuring a stable HIGH signal when the button was not pressed and a low signal when pressed. An LED with a current-limiting resistor was connected to PD4 (digital pin 4) and configured as an output.

To enable interrupts, the External Interrupt Mask Register (EIMSK) was configured to unmask INT0, while the External, while the External Interrupt Control Register A (EICRA) was set to detect a falling edge on PD2, corresponding to the button press (HIGH to LOW transition). The Interrupt Service Routine (ISR) associated with INT0_vect was implemented to toggle the LED state each time the button was pressed. The state transition occurs every time the button is clicked (ON to OFF, OFF to ON).

The project highlighted the advantage of interrupt-driven design over polling, as the microcontroller no longer had to continuously monitor the input state. Instead, it responded only when an event occurred, freeing the CPU for other tasks. The implementation reinforced core concept including register level interrupt configuration, pull-up resistor use for stable inputs, ISR-based event handling. 

By transitioning from polling to interrupts, this project marked the first step into intermediate-level embedded systems programming, providing a foundation for future projects involving timers, communication interfaces, and more complex event coordination. 

# Software Description
## Software Used
* Development tool(s): VS Code
* Development Language: C

## Project Files
* List of .c and .h files: [InterruptLED_main.c](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%204_ATmega328P_InterruptLED/Code/InterruptLED_main.c)
* Source file Descriptions: This source file configures PD4 as an LED output and PD2 (INT0) as a pushbutton input with an internal pull-up resistor. The external interrupt is set to trigger on the falling edge (button press). Each button press toggles the LED state on PD4. The main loop does nothing—LED control is handled entirely in the ISR.
* Makefile location: Project [Makefile](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%204_ATmega328P_InterruptLED/Code/Makefile)
* Compiled outputs location: [hex file](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Project%204_ATmega328P_InterruptLED/Code/main.hex)

# Hardware
1. Microcontroller/board: ATmega328P/ Uno R3 (1)
2. USB cable - Uno R3 compatible (1)
3. LED (1)
4. Resistor (1)
5. Pushbutton (SPST) (1)
6. Jumper wire (4)

# Project Functionality

# Outcomes
* Did it work as intended: Yes it did. 
* Challenges faced: Took a few times generating the code to get the hex file to work properly, most of this was just necessary debugging that needed to occur.
* Lessons Learned: Interrupts offer a significant advantage over simple polling by reducing the CPU's processing load, although their configuration is more complex. 

On the ATmega328P, an Interrupt Service Routine (ISR) must then be defined using the correct interrupt vector, like `ISR(INT0_vect)`, which specifies the code to be executed when the interrupt is triggered. Next. we configure a specific GPIO pin, such as the one for INT0, PD2, as an input. We then define the trigger condition, such as a falling edge for a high-to-low voltage change, which is configured in the External Interrupt Control Register (EICRA) by setting the ISC01 and ISC00 bits. After this, the specific interrupt channel is enabled in the External Interrupt Mask Register (EIMSK) by setting the corresponding bit. Finally, global interrupts are enabled using the sei() function to allow the CPU to process interrupt requests.

To enable the `main()` function to run continuously, a perpetual while loop, denoted as `while(1)`, is necessary. This loop ensures that the program never exits the main function, allowing for the processing of multiple inputs, such as those from the button, without termination.

# Project Progression
* Skill level demonstrated: Intermediate
* How it builds on previous projects: 

- **Project 1: ATmega328P Blink‐Built-in-LED**  
  Introduced basic GPIO output by blinking the onboard LED, laying the groundwork for understanding microcontroller pin control.

- **Project 2: ATmega328P Breadboard-LED-Blink**  
  Expanded on GPIO control by setting up an external LED on a breadboard, enhancing skills in wiring and external component interfacing.

- **Project 3: ATmega328P PushButton-LED-Control**  
  Introduced input handling by using a pushbutton to control an LED, demonstrating basic input reading and output control.

This project further develops these skills by implementing **interrupt-driven input handling**.  
Instead of continuously polling the button state, the microcontroller responds to an **interrupt signal** when the button is pressed, allowing for more efficient and responsive input handling.
