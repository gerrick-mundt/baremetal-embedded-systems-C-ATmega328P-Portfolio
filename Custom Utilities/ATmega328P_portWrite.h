#ifndef ATMEGA328P_PORTWRITE_H
#define ATMEGA328P_PORTWRITE_H

#include <stdint.h>
#include <stdbool.h>

// Port check function
bool uint8t_portCheck(volatile uint8_t *reg);

// Port write function
void uint8t_PortWrite(volatile uint8_t *port, uint8_t pin, bool value);

#endif