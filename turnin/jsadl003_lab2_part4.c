/*	Author: jsadl003
 *      Partner(s) Name: Jason Sadler
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include <math.h>


#endif

int main(void) {
    DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
    DDRB = 0x00; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0x00; PORTC = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    unsigned int tmpA = 0x00; // Temporary variable to hold the value of B
    unsigned int tmpB = 0x00; // Temporary variable to hold the value of A
    unsigned int tmpC = 0x00;
    unsigned int tmpD = 0x00;

    while(1){
      	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
        tmpD = 0x00;
	unsigned  int weight = (tmpA + tmpB + tmpC);
        if(weight >= 0x8D){
	    tmpD = 0x01;
	    
	}
	if(fabs(tmpA - tmpC) >0x50){
	 
	    tmpD = (tmpD) | (0x02);
	   
	}
	
	weight = weight >> 2;
	weight = weight & 0xFC;
	
	tmpD = weight + tmpD;
	PORTD = tmpD;





}
        
    return 0;
}
