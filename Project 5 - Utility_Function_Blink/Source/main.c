#include "ATmega328P_common.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Write the pin as an output
    gpio_direction(&DDRD, 7, OUTPUT);

    // Continue loop forever
    while(1)
    {
        gpio_write(&PORTD, 7, HIGH); // Toggle HIGH
        _delay_ms(1000); // Delay 1 second
        gpio_write(&PORTD, 7, LOW); // Toggle LOW
        _delay_ms(1000); // Delay 1 second
    }
    return 0;
}
