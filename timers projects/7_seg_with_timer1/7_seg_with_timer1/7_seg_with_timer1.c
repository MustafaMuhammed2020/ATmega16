/*
 * _7_seg_with_timer1.c
 *
 * Created: 18/07/2020 01:23:55 ص
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
//including interrupts header file
#include <avr/interrupt.h>

//global variable for counting overflows
unsigned char no_of_ovs =0;

//ISR of timer1
ISR(TIMER2_OVF_vect)
{
	no_of_ovs++;   
	if (no_of_ovs == 123)  //at 123 time is 1 sec
	{
		if (PORTC == 9)
		{
			PORTC = 0;
		}
		else
		{
			PORTC++;  //increasing the 7-seg with one
		}
		no_of_ovs = 0; //clearing no_of_ovs for new cycle
	}
}

//configuration function of timer1
void timer2_config (void)
{
	TCCR2 |= ((1<<FOC0) | (1<<CS02));  //normal mode with FCPU/256 prescaller
	TCNT2 = 0;             //the initial value is 0
	TIMSK |= (1<<TOIE2);  //enables timer2 interrupt
} 

int main(void)
{
	//registers directions and initial values
	DDRC |= ((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3)); //four pins to 7-seg
	PORTC &= (~((1<<PC0) | (1<<PC1) | (1<<PC2) | (1<<PC3)));  //the initial value is 0
	
	//enable global interrupts
	sei();
	
	//timer2 start
	timer2_config();
    while(1)
    {
        //TODO:: Please write your application code 
    }
}