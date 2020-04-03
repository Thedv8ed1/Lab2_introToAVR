/*	Author: jsadl003
 *      Partner(s) Name: Jason Sadler
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Garage open at night-- A garage door sensor connects to
 				PA0 (1 means door open), and a light sensor connects
				to PA1 (1 means light is sensed). Write a program that
				illuminates an LED connected to PB0 (1 means illuminate)
				if the garage door is open at night.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

    while(1){
	tmpA = PINA & 0x01;
	tmpB = PINA & 0x02;
        PORTB = (tmpA && !tmpB);
    }    
    return 0;
}
