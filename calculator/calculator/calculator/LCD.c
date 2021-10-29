/* 
 * LCD.c 
 * 20x4 LCD module 
 * control pins connected to PORTD
 * data pins connected to PORTC
 * author : mostafa gomaa
 */

#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"
#include "standard_types.h"
#include "common_macros.h"

/*implementation of INIT function*/
void LCD_INIT()
{
	LCD_data_direction_port = 0xFF;        /*data pins configured as output pins*/
	LCD_cntrl_direction_port |= ((1<<EN) | (1<<RS) | (1<<RW));  /*all control pins as output*/ 
	LCD_send_command(two_lines_mode);  /*enables the two lines mode 5x8 dots*/
	LCD_send_command(cursor_on);    /*show the cursor*/
	LCD_send_command(clear_screen);   /*clearing the screen*/
}

/*implementation of send_command function*/
void LCD_send_command(u_int8 command)
{
	LCD_cntrl_port &= (~(1<<RS));   /* instruction mode RS-->0 */
	 /*the same as clear_bit(LCD_cntrl_port,RS);*/
	LCD_cntrl_port &= (~(1<<RW));  /* write to LCD RW--> 0 */
	/*the same as clear_bit(LCD_cntrl_port,RW);*/
	_delay_ms(1);
	set_bit(LCD_cntrl_port,EN);  /*enable the lcd*/
	_delay_ms(1);
	LCD_data_port = command; /*sending the command as hex value*/
	_delay_ms(1);
	clear_bit(LCD_cntrl_port,EN);	
	_delay_ms(1); 
}

/*implementation of display_character function*/
void LCD_display_character(u_int8 character)
{
	LCD_cntrl_port |= (1<<RS);   /* instruction mode RS-->1 */
	 /*the same as set_bit(LCD_cntrl_port,RS);*/
	LCD_cntrl_port &= (~(1<<RW));  /* write to LCD RW--> 0 */
	/*the same as clear_bit(LCD_cntrl_port,RW);*/
	_delay_ms(1);
	set_bit(LCD_cntrl_port,EN);  /*enable the lcd*/
	_delay_ms(1);
	LCD_data_port = character; /*sending the character as hex value*/
	_delay_ms(1);
	clear_bit(LCD_cntrl_port,EN);	
	_delay_ms(1);
}

/*implementation of display_string function*/
void LCD_display_string(const char *str)
{
	u_int8 i = 0;  /*counter for the characters*/
	while(str[i] != '\0')  /*the string not ended*/
	{
		LCD_display_character(str[i]); /*displaying the character*/
		i++; /*update the counter*/
	}
}

/*implementation of display_int function*/
void LCD_int_to_str(int data)
{
	char buffer[16]; /*array to hold the characters*/
	itoa(data,buffer,10); /*converting the integer to string*/
	LCD_display_string(buffer); /*display the string*/
}

/*implementation of goto function*/
void LCD_goto(u_int8 row,u_int8 col)
{
	/*first of all we need to evaluate the location*/
	u_int8 location;
	switch (row)
	{
	case 1: 
	    location = col + 0x80;
		break;
    case 2:
	    location = col + 0xC0;
	    break;
	case 3:
	    location = col + 0x94;
	    break;
	case 4 : 
	    location = col + 0xD4;
		break;
	}
	LCD_send_command (location | cursor_to_beginning); /*evaluating the new location*/
}

/*function to display string from specific location*/
void LCD_display_string_at(u_int8 row,u_int8 col,const char *str)
{
	LCD_goto(row,col);  /*go to the location*/
	LCD_display_string(str);  /*display the string*/
}

/*implementation of clear function*/
void CLEAR_LCD()
{
	LCD_send_command(clear_screen); /*send clear screen command*/
}