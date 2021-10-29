/* 
 * 4x4_keypad .c
 * author : mostafa gomaa
 */

/*including 4x4_keypad header file*/
#include "4x4_keypad.h"

/*including common_macros header file*/
#include "common_macros.h"

u_int8 pressed_key(void)
{
	u_int8 rows,columns;
	while(1)
	{
		for(columns=0;columns<n_of_columns;columns++) /*first loop for columns*/
	     {
		         /* 
	              * each column will be low a time while the other columns will be high
	              * enabling the pull-ups for input pins and set the output columns as ones
	              */
	                 keypad_direction_port = (0b00010000<<columns);
	                 keypad_data_port = (~(0b00010000<<columns));
	  
	          for(rows=0;rows<n_of_rows;rows++)
	              {
		             if(bit_is_clear(kepad_input_port,rows))
					  {
						  return adjust_number((rows * n_of_columns) + columns +1);
						  
					  } /*end of if*/
					  
	              } /*end of rows loop*/
				  
	     } /*end of columns loop*/
		
	} /*end of while(1)*/
 	
} /*end of function*/

u_int8 adjust_number(u_int8 button)
{
	switch(button)
	{
		case 1: return 7; 
				break;
		case 2: return 8; 
				break;
		case 3: return 9; 
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4; 
				break;
		case 6: return 5;
				break;
		case 7: return 6; 
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;		
		case 9: return 1; 
				break;
		case 10: return 2; 
				break;
		case 11: return 3; 
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return 13;  /* ASCII of Enter */
				break;			
		case 14: return 0; 
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return button;
		break;
		
	}
}