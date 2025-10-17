#ifndef ATMEGA328P_COMMON_H
#define ATMEGA328P_COMMON_H
#include <stdint.h>

//--------------------------------------------------
// GPIO Type Definitions
//--------------------------------------------------

// Pin state for GPIO
typedef enum
{
    LOW = 0,
    HIGH = 1
} pinState_t;

// Pin direction for GPIO
typedef enum
{
    INPUT = 0,
    OUTPUT = 1
} pinDirection_t;

//--------------------------------------------------
// GPIO Functions
//--------------------------------------------------

// Pin Write Function - Writes pin state HIGH or LOW
void gpio_write(volatile uint8_t *port, uint8_t pin, pinState_t state);

// Pin Direction Set Function - Sets a pin as an input or an output
void gpio_direction(volatile uint8_t *ddr, uint8_t pin, pinDirection_t direction);

#endif
