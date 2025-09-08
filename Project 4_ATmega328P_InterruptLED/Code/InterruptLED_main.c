#include <avr/io.h>
#include <avr/interrupt.h>

// Create Interrupt Service Routine (ISR)
ISR(INT0_vect)
{
    // Write pin PD4 as the opposite of what it just was, this allows you to toggle
    // between light on and light off every time you click the pushbutton
    PORTD ^= (1 << PD4);
}

// Configure GPIO (PD2, PD4) as inputs and outputs, set interrupt trigger,
// set interrupt channel, enable ATmega328P interrupts
int main()
{
// Configure GPIO    
    // Set PD4 as an output (voltage for LED)
    DDRD |= (1 << PD4);

    // Set PD2 as an input
    DDRD &= ~ (1 << PD2);

    // Configure PD2 as pull-up resistor enabled
    PORTD |= (1 << PD2);

// Set interrupt trigger, enable interrupt channel (INT0) and enable global interrupts
    // Set interrupt trigger to be a falling edge (HIGH to LOW) using EICRA
    EICRA &= ~(1 << ISC00);
    EICRA |= (1 << ISC01);

    // Enable interrupt channel
    EIMSK |= (1 << INT0);

    // Enable global interrupts
    sei();

    // Make the function continous
    while(1)
    {
        // Nothing goes here
    }
}
