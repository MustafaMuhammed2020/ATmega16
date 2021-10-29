/*
 * led_patterns.c
 *
 * Created: 14/07/2020 03:08:20 ص
 *  Author: mostafa gomaa
 */ 

#include <avr/io.h>
#include <util/delay.h>
unsigned char i;

void patt1(void)
{
	PORTA=0x01;
	for (i=0;i<8;i++)
	{
		_delay_ms(500);
		PORTA=(PORTA<<1);
	}
}

void patt2(void)
{
	PORTA=0x80;
	for (i=0;i<8;i++)
	{
		_delay_ms(500);
		PORTA=(PORTA>>1);
	}
}

void patt3(void)
{
	PORTA=0x01;
	for (i=0;i<8;i++)
	{
		_delay_ms(500);
		PORTA = PORTA | (PORTA<<1);
		
	}			
}

void patt4(void)
{
	PORTA=0xff;
	for (i=0;i<8;i++)
	{
		_delay_ms(500);
		PORTA=(PORTA>>1);
	}
}

int main(void)
{
	DDRA=0xff;
	PORTA=0x00;
	
    while(1)
    {
        patt1();
		patt2();
		patt3();
		patt4(); 
    }
}