// Header that is the gateway to the ATmega328P & other avr chips
// hardware for baremetal C programming
#include <avr/io.h>

// Main function, used to turn LED on and off with push-button
int main()
{
    // Write PD2 as an input
    DDRD &= ~(1 << PD2);

    // Make PD2 pull-up resistor configuration (PD2 baseline HIGH)
    PORTD |= (1 << PD2);

    // Write PD7 as an output
    DDRD |= (1 << PD7);

    // Generate while loop that continuously checks for input signal
    // and writes PD7 high whenever the button switch attached to 
    // PD2 is high

    while(1) 
    {
        // Read state of PD2
        if(PIND & (1 << PD2))
        {
            // Set PD7 as high (lights the LED)
            PORTD |= (1 << PD7);
        }
        else
        {
            // Set PD7 as low (Leaves LED in off state)
            PORTD &= ~(1 << PD7);
        }
    }
}
