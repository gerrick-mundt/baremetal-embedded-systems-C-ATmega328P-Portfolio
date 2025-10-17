## Step 1: Write Code
1. include necessary headers
2. Write microcontroller logic 

## Step 2: Generate the .hex file
1. Create a _**makefile**_ in the same folder as your main source file. Do 
this by creating a new file and naming it "Makefile".
2. Copy and paste the following: [Makefile Template](https://github.com/gerrick-mundt/baremetal-embedded-systems-C-ATmega328P-Portfolio/blob/main/Makefile%20Template)
3. If your main file is not named main.c update the SRC = main.c line
4. Make sure you have the correct compiler path. If your path is not CC = avr-gcc, change the name to the correct one (e.g. CC = /opt/homebrew/bin/avr-gcc) 
5. Open a terminal in VS code (Terminal > New Terminal)
6. (Optional) Run: “make clean”
7. Run: “make” (this compiles your code)

## Step 3: Upload the program to the Uno R3 using bootloader
1. Connect the Uno R3 to your computer using USB (can use USB to USB-C converter)
2. Open up the terminal in VS Code
3. Open a terminal in VS Code
4. In the terminal, verify the USB ports using: ls /dev/tty.*
5. Write down the USB port you are bootloading over (e.g., /dev/tty.usbmodem1101)
6. Upload the .hex file using avrdude by running the following command: avrdude -c arduino -p m328p -P /dev/tty.usbmodem1101 -b 115200 -U flash:w:main.hex

-c arduino - Tells avrdude to use the arduino bootloader
-p m328P - Specifies the ATmega328P microcontroller
-P /dev/tty.usbmodem14101 - USB port connected to your Uno
-b 115200 - baud rate (symbols per second) for the bootloader
-U flash:w:blink.hex - writes your .hex file to the Uno’s flash memory

7. Wait for upload to complete
8. Run the program
