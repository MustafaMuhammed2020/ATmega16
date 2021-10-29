/*
 * controlling the speed of DC motor using PWM
 *
 * Created: 07/07/2020 01:04:00 ص
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
#define slow PA0
#define meduim PA1
#define high PA2
#define stop PA3
void PWM_Timer0_Init(unsigned char set_duty_cycle)
{
	
	TCNT0=0;                       //set the initial value of timer0
	OCR0=set_duty_cycle;            //the duty cycle value
	DDRB  = DDRB | (1<<PB3);         //the PWM pin set as output
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
}
int main(void)
{
    DDRA=0xf0;   //the first four pins of portA as inputs
	DDRC|=(1<<PC0);
	DDRC|=(1<<PC1);
	PORTC|=((1<<PC0));
	PORTC|=(1<<PC1);  //the motor stops at first
	while(1)
	{
		if (PINA&(1<<slow))
	{
		PORTC|=(1<<PC1);
		PORTC&=~(1<<PC0);
		PWM_Timer0_Init(64);
	}
	else if (PINA&(1<<meduim))
	{
		PORTC|=(1<<PC1);
		PORTC&=~(1<<PC0);
		PWM_Timer0_Init(153);
	}
	else if (PINA&(1<<high))
	{
		PORTC|=(1<<PC1);
		PORTC&=~(1<<PC0);
		PWM_Timer0_Init(255);
	}
	else if (PINA&(1<<stop))
	{
		PORTC|=(1<<PC1);
		PORTC|=(1<<PC0);
	}
	}
	
	
}