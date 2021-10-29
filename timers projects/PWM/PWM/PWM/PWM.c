/*
 * PWM.c
 *
 * Created: 18/07/2020 10:27:30 م
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
//including delay header file
#include <avr/delay.h>

//define switches
#define  slow	PD0
#define intermediate PD1
#define high7	PD2

//configuration function of PWM
void PWM_config (unsigned char speed)
{
	/*PWM mode
	 *FCPU/8 prescaller
	 *non inverting mode
	 */
	TCCR0 |= ((1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01));
	TCNT0 =0;  //initial value
	OCR0 = speed; //the input value
	
	
}

int main(void)
{
	//registers directions and initial value
	DDRD &= (~(1<<PD0)); //first three pins are inputs "switches"
	DDRD &= (~(1<<PD1)); 
	DDRD &= (~(1<<PD2)); 
	
	DDRA |= (1<<PA0);   //first three pins are outputs "leds"
	DDRA |= (1<<PA1);
	DDRA |= (1<<PA2);
	
	DDRB |= (1<<PB1);  //enable and motor pins
	DDRB |= (1<<PB2);
	DDRB |= (1<<PB3);
	
	PORTA =0;         //leds are off
	PORTB |= (1<<PB1); //motor is stopped
	PORTB |= (1<<PB2);
	
	
    while(1)
    {
		//test cases of motor speed
		if ((PIND & (1<<slow)))
		{
			PORTA =0; 
			PWM_config(64);     //25% duty cycle7
			PORTB |= (1<<PB1); //motor is on
	        PORTB &= (~(1<<PB2));
			PORTA |= (1<<PA1);  //illuminate yellow led
			
		}
		 if ((PIND & (1<<intermediate)))
		{
			PORTA =0; 
			PORTA |= (1<<PA0);  //illuminate green led
			PWM_config(128); //54% duty cycle
			PORTB |= (1<<PB1); //motor is on
	        PORTB &= (~(1<<PB2));
			
			
		}
	    if ((PIND & (1<<high7)))
		{
			PORTA =0; 
			PORTA |= (1<<PA2);	//illuminate red led
			PWM_config(250);  //100% duty cycle
			PORTB |= (1<<PB1); //motor is on
	        PORTB &= (~(1<<PB2));
			
		}
		
    }
}