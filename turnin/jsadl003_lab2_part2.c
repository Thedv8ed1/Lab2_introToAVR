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
#endif

int main(void) {
    DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

    while(1){
              unsigned char cntavail;
      unsigned short i;
      cntavail = 0;
      for(i = 0; i < 4; i++){
         if(PINA>>i & 0x01){
            cntavail = cntavail + 1;   
         }
      }
      
      PORTC = cntavail;	
    }    
    return 0;
}
