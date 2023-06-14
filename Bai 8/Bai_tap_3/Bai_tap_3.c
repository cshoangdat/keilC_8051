#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"

sbit btn = P3^1;

void main(void)
{
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	char c = 'A';
	LCD_Init();
	btn = 0;
	while(1){
		if(count%100 == 0){
			if(count1%2 == 0)
		LCD_String_xy(0,0,"Hoang Thanh Dat");
			else
		LCD_String_xy(0,0,"20119214       ");
			count1++;
		}
		if(count%200 == 0){
			if(count2%2 == 0)
		LCD_String_xy(1,0,"KTMT");
			else
		LCD_String_xy(1,0,"20  ");
			count2++;
		}
		if(btn == 1){
			LCD_SetPosition(2,0);
			LCD_String("Char: ");
			LCD_Char(c);
			c++;
			while(btn == 1);
		}
		delayMs(10);
		count++;
	}
}