/*
 * CTC_mode.c
 *
 * Created: 18/07/2020 02:22:52 ص
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
//including interrupts header file
#include <avr/interrupt.h>

//global variable for overflows
unsigned char no_of_ovs =0;

//ISR for CTC mode
ISR(TIMER0_COMP_vect)
{
	no_of_ovs ++;
	if (no_of_ovs == 2)
	{
		PORTB ^= (1<<PB4);
		no_of_ovs = 0;
	}
}
//CTC_TMR0 configuration function
void CTC_TM0 (unsigned char ticks)
{
	/* compare mode
	 * toggle on OC0 pin
	 * prescaller is FCPU/1024 
	*/
	TCCR0 |= ((1<<FOC0) | (1<<WGM01) | (1<<CS00) | (CS02));
	TCNT0 = 0;      //initial value is 0
	OCR0 = ticks;   //number to be compared
	TIMSK |=(1<<OCIE0);  //enables interrupts for CTC mode
	
}

int main(void)
{
	//registers direction and initial values
	DDRB |= (1<<PB4);    //OC0 is output pin
	PORTB &= (~(1<<PB4));  //led is off
	
	//start CTC
	CTC_TM0(250);  //start CMP mode
	
	//enable global interrupts
	sei();
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}