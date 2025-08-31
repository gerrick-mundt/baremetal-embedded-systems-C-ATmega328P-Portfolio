// Defines names of ports and pins, individual bits and
// other registers
#include <avr/io.h>
// Provides simple software delay functions
#include <util/delay.h>

int main(void)
{
    // Set PORTB5 as an output
    DDRB |= (1 << PB5);

    while(1)
    {
        // Set Port B Pin 5 (PB5) high 
        // PORTB = PORTB | (1 << PB5);
        PORTB |= (1 << PB5);

        // Wait 1 seconds (1000 ms)
        _delay_ms(1000);

        // Unset Port B Pin 5 (PB5)
        PORTB &= ~(1 << PB5);

        // Wait 1 seconds (1000 ms)
        _delay_ms(1000);
    }
}
