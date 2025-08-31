# ATmega328P Blinking LED

## Overview
This project demonstrates basic usage of the ATmega328P microcontroller by blinking an LED connected to the PB5 digital GPIO pin. The LED is turned on for 1 second and off for 1 second repeatedly.

## Objective
- Learn the ATmega328P architecture.
- Configure Data Direction Registers (DDR) to set port pins as outputs.
- Control PB5 GPIO to generate a blinking LED signal.

## Hardware
- ATmega328P microcontroller

## Code
- Written in **C** (bare-metal, register-level programming)
- Uses **PB5** (Arduino digital pin 13) for LED output
- No external libraries are required

## Usage
1. Connect an LED with a resistor to PB5.
2. Compile and flash the code to the ATmega328P using your preferred programmer.
3. Observe the LED blinking at 1-second intervals.
