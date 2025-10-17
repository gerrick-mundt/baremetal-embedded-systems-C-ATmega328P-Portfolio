#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Write the pin as an output
    DDRD |= (1 << PD7);

    while(1)
    {
        // Write the pin to high
        PORTD |= (1 << PD7);

        // Delay clock 1s
        _delay_ms(1000);

        // Write the pin low
        PORTD &= ~(1 << PD7);

        // Delay clock 1s
        _delay_ms(1000);

        // Upload the make file to the UNO R3
        // avrdude -c arduino -p m328p -P /dev/tty.usbmodem1101 -b 115200 -U flash:w:main.hex
    }
}
