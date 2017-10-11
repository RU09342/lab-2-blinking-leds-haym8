/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Multiple Blink
 * MSP430F5529
*/

#include <msp430.h>

int main(void) {
	volatile int i = 0;
	volatile int j = 0;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Set the directions of pins 1.0 and 4.7 (LED pins)
	P1DIR = BIT0;
	P4DIR = BIT7;

	// Set the red LED to on to start, stagger the blinking
	P1OUT |= BIT0;
	P4OUT &= ~BIT7;

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
			P4OUT ^= BIT7;
			j = 0;
		}
	}
}
