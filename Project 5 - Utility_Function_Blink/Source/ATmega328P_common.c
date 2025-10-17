#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "ATmega328P_common.h"

//--------------------------------------------------
// GPIO Functions
//--------------------------------------------------

// Pin Read Function - Reads the current pin state


// Pin Write Function - Writes pin state HIGH or LOW
void gpio_write(volatile uint8_t *port, uint8_t pin, pinState_t state)
{
    // Validate port register
    if (port != &PORTB && port != &PORTC && port != &PORTD)
    {
        return; // Invalid port
    }

    // Validate pin (PORTC only has pins 0-6)
    if (pin > 7 || (port == &PORTC && pin > 6))
    {
        return; // Invalid pin
    }

    // Validate state
    if (state != LOW && state != HIGH)
    {
        return; // Invalid state
    }

    // Write pin state
    if (state == HIGH)
    {
        *port |= (1 << pin);
    }
    else
    {
        *port &= ~(1 << pin);
    }
}

// Pin Direction Set Function - Sets a pin as an input or an output
void gpio_direction(volatile uint8_t *ddr, uint8_t pin, pinDirection_t direction)
{
    // Validate Direction Register
    if (ddr != &DDRB && ddr != &DDRC && ddr != &DDRD)
    {
        return; // Invalid port
    }

    // Validate pin (DDRC only has 0-6 available)
    if ((pin > 7) || (ddr == &DDRC && pin > 6))
    {
        return;
    }

    // Validate direction
    if (direction != INPUT && direction != OUTPUT)
    {
        return;
    }

    // Set pin direction
    if (direction == OUTPUT)
    {
        *ddr |= (1 << pin);
    }
    else
    {
        *ddr &= ~(1 << pin);
    }
}

// Pin Toggle Function - Inverts current state from HIGH to LOW or vice versa)
// Activate Internal Pull-up Resistor
// Deactivate Internal Pull-up Resistor