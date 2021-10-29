/*
 * external_interrupt_2.c
 *
 * Created: 15/07/2020 05:16:11 م
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
//including interrupts header file
#include <avr/interrupt.h>

//interrupt service routine
ISR(INT2_vect)
{
	if (PORTC == 9)  //clearing when reaches 9
	{
		PORTC = 0;
	}
	else
	    PORTC ++;  //increasing the seven segment by one
	
}

//configuration function
void INT2_intit(void)
{
	SREG &= (~(1<<7));     //disables global interrupts
	GICR |= (1<<INT2);     //enables INT2 source
	DDRB &= (~(1<<PB2));   //the source pin as input
	MCUCSR &= (~(1<<ISC2));  //the action is falling edge
	SREG |= (1<<7);          //enables global interrupts       
}

int main(void)
{
	//registers direction & initial values
	DDRC |= ((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3)); //first four bits to 7 segment
	PORTC = 0x00;
	
	//calling the interrupt function
	INT2_intit(); 
	
    while(1)
    {
        //main code
		 
    }
}