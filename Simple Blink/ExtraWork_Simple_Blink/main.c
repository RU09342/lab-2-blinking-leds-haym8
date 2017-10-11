/*
 * Mitchell Hay
 * RU09342
 * Lab 2 - Simple Blink
 * MSP430F5529
 */
//******************************************************
//                 MSP430F552x
//             -----------------
//         /|\|                 |
//          | |                 |
//          --|RST              |
//            |                 |
//            |     P3.3/UCA0TXD|------------>
//            |                 | 115200 - 8N1
//            |     P3.4/UCA0RXD|<------------
//
//*******************************************************

char c = 0x00; 					// Initialize input character
char greeting[20] = "Type s, m, f, or o:"; 	// Initial Greeting you should see upon properly connecting your Launchpad
volatile int i = 0;				// Set up counters
volatile int j;

#include <msp430.h>
void main(void) {
	WDTCTL = WDTPW + WDTHOLD;            	// Stop WDT

	// Set Up LEDs
	P1DIR |= BIT0;				// P1.0 LED
	P1OUT |= BIT0;

	P3SEL |= BIT3 + BIT4;                  	// P3.3,4 = USCI_A0 TXD/RXD
	UCA0CTL1 |= UCSWRST;                    // **Put state machine in reset**
	UCA0CTL1 |= UCSSEL_2;                   // SMCLK
	UCA0BR0 = 9;                            // 1MHz 115200 (see User's Guide)
	UCA0BR1 = 0;                            // 1MHz 115200
	UCA0MCTL |= UCBRS_1 + UCBRF_0;          // Modulation UCBRSx=1, UCBRFx=0
	UCA0CTL1 &= ~UCSWRST;                   // **Initialize USCI state machine**
	UCA0IE |= UCRXIE;                       // Enable USCI_A0 RX interrupt

	// Print greeting on startup
	while (greeting[i] != '\0') {
		while (!(UCA0IFG & UCTXIFG))
			;           		// USCI_A0 TX buffer ready?
		{
			UCA0TXBUF = greeting[i];         // TX -> each char from greeting
			i++;
		}
	}

	__bis_SR_register(GIE);       		// Interrupts enabled

	// Loop forever
	while (1) {
		// If RXed char is 's', blink LED slow
		while (c == 's') {
			// toggle bit 0 of P1
			P1OUT ^= BIT0;
			// delay for a while
			for (j = 0; j < 30000; j++)
				;
		}

		// If RXed char is 'm', blink LED medium
		while (c == 'm') {
			// toggle bit 0 of P1
			P1OUT ^= BIT0;
			// delay for a while
			for (j = 0; j < 15000; j++)
				;
		}

		// If RXed char is 'f', blink LED fast
		while (c == 'f') {
			// toggle bit 0 of P1
			P1OUT ^= BIT0;
			// delay for a while
			for (j = 0; j < 7500; j++)
				;
		}

		// If RXed char is 'o', turn LED off
		while (c == 'o') {
			// Turn off LED
			P1OUT &= ~BIT0;
		}
	}
}

// Echo back RXed character, confirm TX buffer is ready first
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A0_VECTOR))) USCI_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
	switch (__even_in_range(UCA0IV, 4)) {
	case 0:
		break;                          // Vector 0 - no interrupt
	case 2:                                 // Vector 2 - RXIFG
		while (!(UCA0IFG & UCTXIFG))
			;             		// USCI_A0 TX buffer ready?
		c = UCA0RXBUF;                  // Set c = RXed Char
		UCA0TXBUF = c;			// TX -> c
		break;
	case 4:					// Vector 4 - TXIGF
		break;
	default:
		break;
	}
}
