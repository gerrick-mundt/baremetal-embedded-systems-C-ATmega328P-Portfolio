#include <avr/io.h>

// SUMMARY: 

// For this project, I am using a push button to select when to provide 
// power to an LED circuit. 

// LED Circuit: The LED circuit consists of a voltage supply, header pin 4 
// (register pin PD4), a resistor, an LED and a ground (GND) return pin. 

// Power Select Circuit: To select when the LED circuit has power, a Single Pole 
// Single Throw (SPST) push button is used. Single Pole means it controls a single
// circuit. Single Throw means it only provides two contact postions 
// OPEN (no connection), CLOSE (connection made). The power select circuit consists
// of an input, header pin 7 (register pin PD7), the SPST switch, and a ground (GND)
// return pin.

// The purpose of this program is to connect the these two circuits via the 
// microcontoller.

int main()
{
    // Set PD4 (Voltage Supply) to an output (Direction register 1 value)
    DDRD |= (1 << PD4);

    // Set PD7 (SPST Input Pin) to an input (Direction register 0 value)
    DDRD &= ~(1 << PD7);

    // Set Input type to floating input (Read register 0 value)
    PORTD &= ~(1 << PD7);

    // This while loop continuously reads the state of pin PD7
    // (SPST button circuit input) and depending on the value of that pin read,
    // writes the LED circuit output either HIGH or LOW
    while(1)
    {
        // Read state of PD7
        if(!(PIND & (1 << PD7)))
        {
            // Write PD4 HIGH
            PORTD |= (1 << PD4);
        }
        else
        {
            // Write PD4 LOW
            PORTD &= ~(1 << PD4);
        }
    }
}   
