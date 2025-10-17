# ==========================================================
# Makefile for ATmega328P Project
# Author: Gerrick Mundt
# ==========================================================

# MCU and clock frequency
MCU = atmega328p
F_CPU = 16000000UL

# Compiler and tools
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -std=c11 -Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)

# File paths
SRC = /Users/gerrickmundt/Documents/Baremetal_Code/ATmega328P_common.c \
      /Users/gerrickmundt/Documents/Baremetal_Code/main.c

INC = -I/Users/gerrickmundt/Documents/Baremetal_Code

# Output file name
TARGET = main

# Default rule
all: $(TARGET).hex

# Compile: generate ELF and HEX files
$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(TARGET).elf

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

# Clean up build files
clean:
	rm -f $(TARGET).elf $(TARGET).hex

# Upload to ATmega328P using avrdude (edit port if needed)
upload: $(TARGET).hex
	avrdude -c arduino -p m328p -P /dev/tty.usbmodem1101 -b 115200 -U flash:w:$(TARGET).hex

# ==========================================================
# End of Makefile
# ==========================================================
