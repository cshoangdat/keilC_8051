#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include "keypad4x4.h"
#include "dht11.h"
#include "stdio.h"
#include <String.h>
sbit led = P2^0;
void main(void)
{
	char temp_value[30];
	char num1 = 0;
	char num2 = 0;
	char num3 = 0;
	char num4 = 0;
	int num_up;
	int num_down;
	int i;
	unsigned char res;
	unsigned char res_update;
	led = 0;
	LCD_Init();
	//LCD_Command(0x0C);
	initKeypad();
	while(1)
	{
		res = dht_read();
		LCD_String_xy(0,0,"Nguong tren: ");
		LCD_String_xy(1,0,"Nguong duoi: ");
		
		//doc gia tri nhiet do
		LCD_String_xy(2,0,"Nhiet do: ");
		sprintf(temp_value,"%d",(int)temp);
		LCD_String_xy(2,10,temp_value);
		LCD_String_xy(2,13,"oC");
		delayMs(100);
		
		//nguong tren
		LCD_SetPosition(0,13);
		num1 = ReadKeyPressed();
		LCD_Char(num1);
		delayMs(200);
		LCD_SetPosition(0,14);
		num2 = ReadKeyPressed();
		LCD_Char(num2);
		delayMs(200);
		num_up = (num1-48)*10+(num2 -48);
		
		//nguong duoi
		LCD_SetPosition(1,13);
		num3 = ReadKeyPressed();
		LCD_Char(num3);
		delayMs(200);
		LCD_SetPosition(1,14);
		num4 = ReadKeyPressed();
		LCD_Char(num4);
		delayMs(200);
		num_down = (num3-48)*10 + (num4-48);
		
		//main
		if(num_up<=num_down){
			LCD_String_xy(3,0,"vui long nhap lai");
			delayMs(500);
			LCD_Command(0x01);
		}
		if(num_up>num_down){
			if((int)temp > num_up || (int)temp<num_down){
				LCD_String_xy(3,0,"Warning!!! Warning!!!");
				while((int)temp > num_up || (int)temp < num_down){
					led = ~led;
					delayMs(200);
					}
				}
			else{
				LCD_String_xy(3,0,"Nhiet do on dinh");
			}
		}
	}
}