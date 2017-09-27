// Blink 1 LED
#include <msp430.h> 
/*
 * main.c
 */
int main(void) {
	
  // Set up integer counter
  volatile int i;

  // stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;

  // Set up bit 0 of P1 as output
  P1DIR = 0x01;

  // Initialize bit 0 of P1 to 0
  P1OUT = 0x00;

  // Loop forever
  for (;;) {
    // Toggle bit 0 of P1
    P1OUT ^= 0x01;
    // Delay for a while
    for (i = 0; i < 0x6000; i++);
  }
}
