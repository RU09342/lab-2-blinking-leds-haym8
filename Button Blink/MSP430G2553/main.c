/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Button Blink
 * MSP430G2553
 */

#include  <msp430g2553.h> 

void main(void) {
	// Watchdog setup
	WDTCTL = WDTPW + WDTHOLD;

	// Set LED as output
	P1DIR |= BIT0;

	// Button setup
	// Set Button as input
	P1DIR &= ~BIT3;

	// Set pull up resistor as output to Pin 1.3
	P1OUT |= BIT3;

	// Enable pull up resistor
	P1REN |= BIT3;

	while (1) {
		// while the button is pressed turn LED off
		while ((P1IN & BIT3) != BIT3) {
			// Turn off LED
			P1OUT &= ~BIT0;
		}
		// Turn on LED otherwise
		P1OUT |= BIT0;               // Enable RED LED
	}
}
