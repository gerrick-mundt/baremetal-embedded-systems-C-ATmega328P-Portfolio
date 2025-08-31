# MCU and Clock
MCU = atmega328p
F_CPU = 16000000UL

# Compiler and Flags
CC = /opt/homebrew/bin/avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

# Files
TARGET = main
SRC = blinkLED_main.c

# Rules
all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -R .eeprom $< $@

clean:
	rm -f $(TARGET).elf $(TARGET).hex

.PHONY: all clean
