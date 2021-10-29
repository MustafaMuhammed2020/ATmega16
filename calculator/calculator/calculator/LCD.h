#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

/*
 * 20x4 lcd data pins will be connected to PORTC
 * control pins will be connected to PORTD
 */


#include <avr/io.h>
#include "standard_types.h"

/*LCD module configuration*/
#define LCD_cntrl_port PORTD
#define LCD_data_port PORTC
#define LCD_data_direction_port DDRC
#define LCD_cntrl_direction_port DDRD
#define RS PD4
#define RW PD6
#define EN PD5

/*define some commands*/
#define clear_screen 0x01
#define cursor_to_beginning 0x80
#define two_lines_mode 0x38
#define cursor_on 0x0E


/*function to initialize the LCD module*/
void LCD_INIT();
/*function to send commend*/
void LCD_send_command(u_int8 command);
/*function to display character*/
void LCD_display_character(u_int8 character);
/*function to display string*/
void LCD_display_string(const char *str);
/*function to display integer*/
void LCD_int_to_str(int data);
/*function to go to specific location*/
void LCD_goto(u_int8 row,u_int8 col);
/*function to display string at specific location*/
void LCD_display_string_at(u_int8 row,u_int8 col,const char *str);
/*function to clear the LCD*/
void CLEAR_LCD();

#endif // LCD_H_INCLUDED
