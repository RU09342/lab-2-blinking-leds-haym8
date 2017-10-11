/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Simple Blink
 * MSP430F5529
*/

#include <msp430.h>

int main(void) {
  volatile int i;

  // stop watchdog timer
  WDTCTL = WDTPW | WDTHOLD;
  // set up bit 0 of P1 as output
  P1DIR = BIT0;
  // intialize bit 0 of P1 to 0
  P1OUT = 0x00;

  // loop forever
  for (;;) {
    // toggle bit 0 of P1
    P1OUT ^= BIT0;
    // delay for a while
    for (i = 0; i < 30000; i++);
  }
}
