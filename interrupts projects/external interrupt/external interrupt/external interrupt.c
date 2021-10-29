﻿/*
 * external_interrupt.c
 *
 * Created: 15/07/2020 03:50:43 م
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect)                   // External INT0 Interrupt Service Routine
{
	PORTC = PORTC ^ (1<<PC0);   //toggle led state
	_delay_ms(500);
	PORTC = PORTC ^ (1<<PC0); 
}

void INT0_Init(void)           //External INT0 enable and configuration function
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

int main(void)
{
	INT0_Init();              // Enable external INT0

	DDRC  = DDRC | (1<<PC0);  // Configure pin PC0 in PORTC as output pin
	PORTC = PORTC & (~(1<<PC0)); // Initialization Led is off at the beginning(Negative Logic)
    while(1)
    {
							
	}					
}
