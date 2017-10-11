/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Multiple Blink
 * MSP430G2553
 */

#include <msp430g2553.h>

int main(void) {
	volatile int i;
	volatile int j;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Set the directions of pins 1.0 and 1.6 (LED pins)
	P1DIR |= BIT0;
	P1DIR |= BIT6;

	// Set the red LED to on to start, stagger the blinking
	P1OUT |= BIT0;
	P1OUT &= ~BIT6;

	while (1) {
		// Delay
		i++;
		j++;

		// Toggle LEDs on or off
		if (i >= 10000) {
			P1OUT ^= BIT0;
			i = 0;
		}

		if (j == 20000) {
			P1OUT ^= BIT6;
			j = 0;
		}

	}
}
