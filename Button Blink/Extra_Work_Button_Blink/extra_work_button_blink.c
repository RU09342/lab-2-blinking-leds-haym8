/*
 * Mitchell Hay
 * RU09342
 * Lab 2 Button Blink Extra Work
 * MSP430G2553
*/

#include  <msp430g2553.h>

void main(void)
{
	// Watchdog setup
	WDTCTL = WDTPW + WDTHOLD;

	// Set LED as output
	P1DIR |= BIT0;
	P1OUT &= ~BIT0;

	// Button setup
	// Set Button as input
	P1DIR &= ~BIT3;

	// Set pull up resistor as output to Pin 1.3
	P1OUT |= BIT3;

	// Enable pull up resistor
	P1REN |= BIT3;

	// Set up button press counter
	int j = 0;
	while (1)
	{
		// Use i for delay counter
		volatile int i;
		// When button is pressed, change speed
	    	while ((P1IN & BIT3) != BIT3)
	    	{
	    		j++;
	    		for (i = 0; i < 0x6000; i++);	// Delay to account for debouncing

	    	}

	    	//
	    	if (j == 1)
	    	{
	    		while(1)
	    		{
	    			// toggle bit 0 of P1
	    			P1OUT ^= 0x01;
	    			// delay for a while
	    			for (i = 0; i < 0x6000; i++);
				// Break out of while loop when button is pressed
	    			if ((P1IN & BIT3) != BIT3)
	    			{
	    				P1OUT &= ~BIT0;
	    				break;
	    			}
	    		}
	    	}

	    	if (j == 2)
	    	{
	    	    	while(1)
	    	    	{
	    	    		// toggle bit 0 of P1
	    	    		P1OUT ^= 0x01;
	    	    		// delay for a while
	    	    		for (i = 0; i < 0x3000; i++);
				// Break out of while loop when button is pressed
	    	    		if ((P1IN & BIT3) != BIT3)
	    	    		{
	    	    			P1OUT &= ~BIT0;
	    	    			break;
	    	    		}
	    	    	}
	    }

	    if (j == 3)
	    {
	    	while(1)
	      	{
	      		// toggle bit 0 of P1
	    	    	P1OUT ^= 0x01;
	    	    	// delay for a while
	    	    	for (i = 0; i < 0x1500; i++);
			// Break out of while loop when button is pressed
	    	    	if ((P1IN & BIT3) != BIT3)
	    	    	{
				// LED turned off
	    	    		P1OUT &= ~BIT0;
	    	    	    	break;
	    	    	}
	    	}
	    }
		
	    // Reset button counter after highest speed
	    else if (j > 3)
	    {
	    	j -= 4;
	    }

	}
}
