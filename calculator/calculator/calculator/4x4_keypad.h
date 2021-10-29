/* 
 * 4x4_keypad .h
 * author : mostafa gomaa
 */

/*including avr/io header file*/
#include <avr/io.h>

/*including the standard types header file*/
#include "standard_types.h"

/*
 * keypad configuration 
 * the keypad will be connected to PORTA
 */
#define keypad_direction_port DDRA
#define keypad_data_port PORTA
#define kepad_input_port PINA
#define n_of_rows 4  /*defining the number of rows*/
#define n_of_columns 4 /*defining the number of columns in the module*/

/*function to return the pressed key*/
u_int8 pressed_key(void);

/*function to adjust the pressed number*/
u_int8 adjust_number(u_int8 button);