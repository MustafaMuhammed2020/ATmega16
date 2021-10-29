/*
 * timer0.c
 *
 * Created: 17/07/2020 11:54:10 م
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
//including interrupts header file
#include <avr/interrupt.h>

//global interrupt variable for overflows
unsigned char number_of_ovs;

//interrupt service routine
ISR(TIMER0_OVF_vect)
{
	number_of_ovs++;
	if (number_of_ovs == 2)  //after two overflows
	{
		PORTC ^= (1<<PC0);  //toggle the pin state
		number_of_ovs=0;   //clear the overflows counter to start another cycle
	}
}

//configuration function for timer0
void timer0_config (void)
{
	TIMSK |= (1<<TOIE0); //enables timer0 overflow interrupt
	TCNT0 =0;           //initial value of timer0 is 0
	TCCR0 |= ((1<<FOC0) | (1<<CS00) | (1<<CS02));  //normal mode with FCPU/1024 prescaller
}	

int main(void)
{
	//registers direction and initial values
	DDRC |= (1<<PC0);  //the led is output pin
	PORTC &= (~(1<<PC0));  //led is off
	sei();           //enable global interrupts
	timer0_config();  //start timer 
	
    while(1)
    {
        //main code 
    }
}