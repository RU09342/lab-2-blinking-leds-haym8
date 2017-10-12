/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Simple Blink
 * MSP430G2553
*/

#include <msp430g2553.h>

int main(void) {
  volatile int i;

  // stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;
  // Set up bit 0 of P1 as output
  P1DIR = 0x01;
  // Intialize bit 0 of P1 to 0
  P1OUT = 0x00;

  // loop forever
  for (;;) {
    // Toggle bit 0 of P1
    P1OUT ^= 0x01;
    // Delay for a while
    for (i = 0; i < 0x6000; i++);
  }
}
