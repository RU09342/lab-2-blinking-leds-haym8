/*
 *

 * Mitchell Hay
 * RU09342
 * Lab 2 Multiple Blink
 * MSP430G2553


#include <msp430g2553.h>

int main(void) {
	volatile int i;

	// stop watchdog timer
	WDTCTL = WDTPW | WDTHOLD;

	// Set the directions of pins 1.0 and 1.6 (LED pins)
	P1DIR = 0x01;
	P1DIR = 0x40;

	// Set the red LED to on to start, stagger the blinking
	P1OUT = 0X01;

	for(;;)
	{
		// Delay
		for(i = 0; i < 10000; i++);
		// Toggle LEDs on or off
		P1OUT ^= 0x41;
	}
}

*/
