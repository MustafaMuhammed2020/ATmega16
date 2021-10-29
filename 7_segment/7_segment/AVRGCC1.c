/*
 * 7_segment.c
 *
 * Created: 07/07/2020 08:00:23 م
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
#include <util/delay.h>         /* Clock is 1Mhz by Default */

int main(void)
{
	 char num = 0;
	DDRA  = DDRA & (~(1<<PA0)); // configure pin 4 of PORTD to be input pin
	DDRC |= 0x0F; // configure all pins of PORTC as output pins
	
	// initialize the 7-segment
	
	PORTC=0;
    while(1)
    {
		// check if the push button is pressed or not
		if( PINA & (1<<PA0) )
		{
			_delay_ms(30);
			//second check due to switch bouncing
			if( PINA & (1<<PA0) )
			{
				if((PORTC & 0x0F) == 9)
				{
					// if overflow occurs
					num = 0;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
				else
				{
					// increment 7-segment every press
					num++;
					PORTC = (PORTC & 0xF0) | (num & 0x0F);
				}
			}
			while( PINA & (1<<PA0) ){} // wait until switch is released
			}											   
    }
}
