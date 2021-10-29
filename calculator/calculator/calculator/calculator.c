/*
 * calculator.c
 * this code simulates a simple calculator
 * Created: 9/24/2020 1:45:54 AM
 * Author: mostafa gomaa
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include "common_macros.h"
#include "standard_types.h"
#include "4x4_keypad.h"
#define F_CPU 1000000UL   /*frequency of MC*/

/*macros for mathematical operations*/
#define add(num1 ,num2) ((num1) + (num2)) /*macro to add numbers*/
#define mul(num1,num2)  ((num1) * (num2)) /*macro to multiply numbers*/
#define div(num1,num2)  ((num1) / (num2)) /*macro for division*/
#define sub(num1,num2)  ((num1) - (num2)) /*macro for subtraction*/

int main(void)
{
	u_int8 num1 =0 , num2 = 0 , operation = 0 ; 
	LCD_INIT(); /*initializing the LCD module*/
			
    while(1)
    {
		
		LCD_display_string_at(1,1,"SIMPLE CALCULATOR"); /*starting phrase*/
		LCD_display_string_at(2,1,"serves two numbers");
		LCD_display_string_at(3,1,"PRESS ON TO START"); /*starting the program*/
		while(pressed_key() != 13);
		{
			_delay_ms(300);
			CLEAR_LCD();
			num1 = pressed_key();
			LCD_goto(1,1);
			LCD_int_to_str(num1);
			_delay_ms(300);
			operation = pressed_key();
			LCD_goto(1,3);
			LCD_display_character(operation);
			_delay_ms(300);
			num2 = pressed_key();
			LCD_goto(1,5);
			LCD_int_to_str(num2);
			_delay_ms(300);
			while(pressed_key() != '=');
			{
				if(operation == '+') /*sum process*/
				{
					LCD_goto(3,2);
					LCD_display_string_at(3,3,"THE SUM IS :");
					LCD_int_to_str(add(num1,num2));
				}
				else if(operation == '*') /*production process*/
				{
					LCD_goto(3,2);
					LCD_display_string_at(3,3,"PRODUCTION IS :");
					LCD_int_to_str(mul(num1,num2));
				}
				else if(operation == '%') /*division process*/
				{
					if(num2 == 0) /*division by zero*/
					{
						LCD_display_string_at(3,3,"devision by zero");
						LCD_display_string_at(4,3,"is not valid");
						
					}
					else
					{
						LCD_goto(3,2);
						LCD_display_string_at(3,3,"DIVISION IS :");
						LCD_int_to_str(div(num1,num2));
						
					}
				}
				else if(operation == '-') /*subtraction process*/
				{
					
					LCD_display_string_at(3,1,"SUBTRACTION IS :");
					LCD_int_to_str(sub(num1,num2));
				}
				
			}
			_delay_ms(1000);
			CLEAR_LCD();
		}
		
    }
}