/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Simple Blink
 * MSP430FR6989
 */

#include  <msp430.h>

void main(void)
{
	// Watchdog setup
	WDTCTL = WDTPW + WDTHOLD;

	// Disable the GPIO power-on default high-impedance mode
	PM5CTL0 &= ~LOCKLPM5;


	// Set LED as output
	P1DIR |= BIT0;

	// Button setup
	// Set Button as input
	P1DIR &= ~BIT1;

	// Set pull up resistor as output to Pin 2.1
	P1OUT |= BIT1;

	// Enable pull up resistor
	P1REN |= BIT1;

	while (1)
	{
		// while the button is pressed turn LED off
	    while ((P1IN & BIT1) != BIT1)
	    {
	    	// Turn off LED
	        P1OUT &= ~BIT0;
	    }
	    // Turn on LED
	    P1OUT |= BIT0;               // Enable RED LED
	}
}
