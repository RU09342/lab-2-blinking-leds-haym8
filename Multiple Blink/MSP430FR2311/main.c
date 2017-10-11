/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Simple Blink
 * MSP430FR6989
 */

#include <msp430.h>

int main(void) {
	volatile int i = 0;
	volatile int j = 0;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Disable the GPIO power-on default high-impedance mode
	PM5CTL0 &= ~LOCKLPM5;


	// Set the directions of pins 1.0 and 4.7 (LED pins)
	P1DIR = BIT0;
	P2DIR = BIT0;

	// Set the red LED to on to start, stagger the blinking
	P1OUT |= BIT0;
	P2OUT &= ~BIT0;

	while(1)
	{
		// Delay
		i++;
		j++;

		// Toggle LEDs on or off
		if (i >= 10000)
		{
			P1OUT ^= BIT0;
			i = 0;
		}

		if (j == 20000)
		{
			P2OUT ^= BIT0;
			j = 0;
		}
	}
}
