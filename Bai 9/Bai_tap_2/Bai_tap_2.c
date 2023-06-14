#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include "keypad4x4.h"
#include "stdio.h"


void setup(){
	LCD_Init();
	initKeypad();
}

void main(void)
{
	char num1 = 0;
	char num2 = 0;
	char chuoi[30];
	int num1_value;
	int num2_value;
	int sum;
	setup();
	while(1){
		LCD_SetPosition(0,0);
		num1 = ReadKeyPressed();
		LCD_Char(num1);
		delayMs(200);
		
		LCD_String_xy(0,1,"+");
		
		LCD_SetPosition(0,2);
		num2 = ReadKeyPressed();
		LCD_Char(num2);
		delayMs(200);
		
		LCD_String_xy(1,0,"=");
		
		if(num1>=48)
		num1_value = num1 - 48;
		
		if(num2>=48)
		num2_value = num2 - 48;
		
		if(num1 >= 48 && num2>= 48){
		sum = num1_value + num2_value;
		sprintf(chuoi,"%d",sum);
			if(sum>=10)
				LCD_String_xy(1,1,chuoi);
			else{
				LCD_String_xy(1,1,chuoi);
				LCD_String_xy(1,2," ");
			}
		}
		if(num1<48 || num2 <48 || num1 == 61 || num2 == 61 || num1 == 67 || num2 == 67){
		LCD_String_xy(1,1,"ERROR");
		delayMs(500);
		LCD_Command(0x01);
		}
	}
}