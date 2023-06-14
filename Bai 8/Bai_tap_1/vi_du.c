#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"

void main(void)
{
	char c = 'A';
	LCD_Init();
	LCD_String_xy(0,0,"Hoang Thanh Dat");
	LCD_String_xy(1,0,"20119214");
	LCD_String_xy(2,0,"KTMT");
	LCD_SetPosition(3,0);
	LCD_String("Char: ");
	while(1){
		LCD_Char(c);
		c++;
		delayMs(1000);
	}
}