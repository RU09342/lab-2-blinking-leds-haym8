/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Simple Blink
 * MSP430FR2311
 */

#include <msp430.h>

int main(void) {
	// Make counters
	volatile int i = 0;
	volatile int j = 0;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Disable the GPIO power-on default high-impedance mode
	PM5CTL0 &= ~LOCKLPM5;


	// Set the directions of pins 1.0 and 2.0 (LED pins)
	P1DIR = BIT0;
	P2DIR = BIT0;

	// Start LEDs off
	P1OUT &= ~BIT0;
	P2OUT &= ~BIT0;

	while(1)
	{
		// Delay
		i++;
		j++;

		// Toggle LED1 on or off
		if (i >= 10000)
		{
			P1OUT ^= BIT0;
			i = 0;
		}
		
		// Toggle LED2 on or off, slower rate
		if (j == 20000)
		{
			P2OUT ^= BIT0;
			j = 0;
		}
	}
}
