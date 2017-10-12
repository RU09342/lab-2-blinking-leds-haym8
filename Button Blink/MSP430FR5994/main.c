/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Button Blink
 * MSP430FR5994
 */

#include  <msp430.h>

void main(void) {
	// Watchdog setup
	WDTCTL = WDTPW + WDTHOLD;

	// Disable the GPIO power-on default high-impedance mode
	PM5CTL0 &= ~LOCKLPM5;

	// Set LED as output
	P1DIR |= BIT0;

	// Button setup
	// Set Button as input
	P5DIR &= ~BIT6;

	// Set pull up resistor as output to Pin 5.6
	P5OUT |= BIT6;

	// Enable pull up resistor
	P5REN |= BIT6;

	while (1) {
		// while the button is pressed turn LED off
		while ((P5IN & BIT6) != BIT6) {
			// Turn off LED
			P1OUT &= ~BIT0;
		}
		// Turn on LED
		P1OUT |= BIT0;               // Enable RED LED
	}
}
