#include <msp430.h>

int main(void) {
	volatile int i = 0;
	volatile int j = 0;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Disable the GPIO power-on default high-impedance mode
	PM5CTL0 &= ~LOCKLPM5;


	// Set the directions of pins 1.0 and 4.7 (LED pins)
	P1DIR |= BIT0;
	P1DIR |= BIT1;

	// Set both LEDs off
	P1OUT |= BIT0;
	P1OUT &= ~BIT1;

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
			P1OUT ^= BIT1;
			j = 0;
		}
	}
}
