/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Simple Blink
 * MSP430F5529
*/

#include <msp430.h>

int main(void) {
  // Set up counter
  volatile int i;

  // stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;
  // Set up bit 0 of P1 as output
  P1DIR = BIT0;
  // Intialize bit 0 of P1 to 0
  P1OUT = BIT0;

  // loop forever
  for (;;) {
    // Toggle bit 0 of P1
    P1OUT ^= BIT0;
    // Delay for a while
    for (i = 0; i < 30000; i++);
  }
}
