#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include "dht11.h"
#include "stdio.h"

void main(void)
{
	char temp_value[30];
	char humid_value[30];
	unsigned char res;
	LCD_Init();
	LCD_Command(0x0C);
	while(1)
	{
		res = dht_read();
		LCD_String_xy(0,0,"Nhiet do: ");
		LCD_String_xy(1,0,"Do am: ");
		sprintf(temp_value,"%d",(int)temp);
		sprintf(humid_value,"%d",(int)humi);
		LCD_String_xy(0,10,temp_value);
		LCD_String_xy(0,13,"oC");
		LCD_String_xy(1,10,humid_value);
		LCD_String_xy(1,13,"%");
		delayMs(100);
	}
}