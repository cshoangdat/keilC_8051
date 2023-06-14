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
	char calc = 0;
	char chuoi[30];
	int num1_value;
	int num2_value;
	int sum;
	int sub;
	int multi;
	float div;
	setup();
	while(1){
		LCD_SetPosition(0,0);
		num1 = ReadKeyPressed();
		LCD_Char(num1);
		delayMs(200);
		
		LCD_SetPosition(0,1);
		calc = ReadKeyPressed();
		LCD_Char(calc);
		delayMs(200);
		
		LCD_SetPosition(0,2);
		num2 = ReadKeyPressed();
		LCD_Char(num2);
		delayMs(200);
		
		if(calc == 42 || calc == 43 || calc == 45 || calc == 47)
			LCD_String_xy(0,3,"=");
		else
			LCD_Command(0x01);
		
		if(num1>=48)
			num1_value = num1 - 48;
		
		if(num2>=48)
			num2_value = num2 - 48;
		
		
		if(num1<48 || num2 <48 || num1 == 61 || num2 == 61 || num1 == 67 || num2 == 67){
			LCD_String_xy(0,4,"ERROR");
			delayMs(500);
			LCD_Command(0x01);
		}
		//cong
		if(calc == 43){
			if(num1 >= 48 && num2>= 48){
			sum = num1_value + num2_value;
			sprintf(chuoi,"%d",sum);
				if(sum>=10){
					LCD_String_xy(0,4,chuoi);
					LCD_String_xy(0,6,"  ");
				}
				else{
					LCD_String_xy(0,4,chuoi);
					LCD_String_xy(0,5,"   ");
				}
			}
		}
		//tru
	if(calc == 45){
		if(num1 >= 48 && num2>= 48){
		sub = num1_value - num2_value;
		sprintf(chuoi,"%d",sub);
			if(sub<0){
				LCD_String_xy(0,4,chuoi);
				LCD_String_xy(0,6,"   ");
			}
			else{
				LCD_String_xy(0,4,chuoi);
				LCD_String_xy(0,5,"   ");
			}
		}
	}
	//nhan
	if(calc == 42){
		if(num1 >= 48 && num2>= 48){
		multi = num1_value * num2_value;
		sprintf(chuoi,"%d",multi);
			if(multi>=10){
				LCD_String_xy(0,4,chuoi);
				LCD_String_xy(0,6,"  ");
			}
			else{
				LCD_String_xy(0,4,chuoi);
				LCD_String_xy(0,5,"  ");
			}
		}
	}
	//chia
		if(calc == 47){	
			if(num1 >= 48 && num2>= 48){
			div = (float)num1_value / num2_value;
			sprintf(chuoi,"%.2f",div);
				if(div != (int)div){
					LCD_String_xy(0,4,chuoi);
				}
				if(div == (int)div){
					LCD_String_xy(0,4,chuoi);
					LCD_String_xy(0,5,"   ");
				}
			}
		}
	}
}