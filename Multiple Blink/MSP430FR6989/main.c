#include <msp430.h>

int main(void) {
	volatile int i = 0;
	volatile int j = 0;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Disable the GPIO power-on default high-impedance mode
	PM5CTL0 &= ~LOCKLPM5;

	// Set the directions of pins 1.0 and 9.7 (LED pins)
	P1DIR = BIT0;
	P9DIR = BIT7;

	// Start both LEDs off
	P1OUT &= ~BIT0;
	P9OUT &= ~BIT7;

	// Loop forever
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
			P9OUT ^= BIT7;
			j = 0;
		}
	}
}
