#include <REGX52.H>
#include "LCD2004.h"
#include <stdio.h>


void main(void)
{
	float a;
	char chuoi[30];
	
	LCD_Init();
	a = 123.543;
	sprintf(chuoi,"KQ: %.2f",a);
	LCD_String_xy(1,3,chuoi);
	while(1){}
}