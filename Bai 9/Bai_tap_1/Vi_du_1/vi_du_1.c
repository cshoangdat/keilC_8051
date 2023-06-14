#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include "keypad4x4.h"


void main(void)
{
	char key = 0;
	LCD_Init();
	
	LCD_String_xy(0,0,"Keypad 4x4 demo");
	initKeypad();
	
	LCD_SetPosition(2,0);
	while(1){
		key = ReadKeyPressed();
		LCD_Char(key);
		delayMs(200);
	}
}