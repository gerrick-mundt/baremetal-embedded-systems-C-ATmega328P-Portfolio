#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>

//--------------------------------------------------
// Check if uint8_t register input is writable
//--------------------------------------------------
bool uint8t_portCheck(volatile uint8_t *reg)
{
    return (
        // GPIO
        reg == &PORTB || reg == &PORTC || reg == &PORTD ||
        reg == &DDRB  || reg == &DDRC  || reg == &DDRD  ||
        // SPI
        reg == &SPCR  || reg == &SPDR  ||
        // UART
        reg == &UCSR0A || reg == &UCSR0B || reg == &UDR0 ||
        // ADC
        reg == &ADCSRA || reg == &ADMUX || reg == &ADCH || reg == &ADCL ||
        // Timers
        reg == &TCCR0A || reg == &TCCR0B || reg == &OCR0A || reg == &OCR0B ||
        reg == &TCCR1A || reg == &TCCR1B || reg == &OCR1AH || reg == &OCR1AL ||
        reg == &TCCR2A || reg == &TCCR2B || reg == &OCR2A || reg == &OCR2B ||
        // Misc control
        reg == &MCUCR  || reg == &MCUSR || reg == &WDTCSR
    );
}

//--------------------------------------------------
// Port write function for 8-bit registers
//--------------------------------------------------
void uint8t_PortWrite(volatile uint8_t *port, uint8_t pin, bool value)
{
    // Error Case: Port input is not valid
    if(!uint8t_portCheck(port)) return;
    
    // Error Case: Pin input is not valid
    if (pin > 7) return;
    
    // Nominal Case
    if(value)
    {
        *port |= (1 << pin); // Set bit high
    }
    else
    {
        *port &= ~(1 << pin); // Set bit low
    }
}
