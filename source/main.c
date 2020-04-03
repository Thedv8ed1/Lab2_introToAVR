/*	Author: jsadl003
 *  Partner(s) Name: Jason Sadler
 *	Lab Section: 021
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; // Configure port B's 8 pins as outputs
    PORTB = 0x00; // Initialize PORTB output to 0’s
    /* Insert your solution below */
    unsigned char temp_input = 0x00;
    while (1) {
        temp_input = PINA;
	PORTB = temp_input;	// Writes port B's 8 pins with the values on port A's 8 pins
    }
    return 1;
}
