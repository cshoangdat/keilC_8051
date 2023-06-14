#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"
#include <stdio.h>

sbit L1 = P2^0;
sbit L2 = P2^1;
sbit B1 = P3^0;
sbit B2 = P3^1;
sbit UP = P3^2;
sbit DOWN = P3^3;

int i = 0;
int T = 5;
char chuoi[30];
char arr[30];

void setup(){
	LCD_Init();
	L1 = 0;
	L2 = 0;
	B1 = 0;
	B2 = 0;
	UP = 0;
	DOWN = 0;
	T = 5;
	LCD_String_xy(0,0,"LED01: OFF");
	LCD_String_xy(1,0,"LED02: OFF");
	LCD_String_xy(2,0,"T = 5s");
}

void main(void){
	setup();
	while(1){
		if(UP == 1){
			T += 1;
			sprintf(chuoi,"%d",T);
			LCD_String_xy(2,4,chuoi);
			if(T>=10) LCD_String_xy(2,6,"s");
			while (UP == 1){};
		}
		if(DOWN == 1){
			T -= 1;
			if(T<=0) T = 0;
			if(T<10){
				LCD_String_xy(2,5,"s ");
			}
			sprintf(chuoi,"%d",T);
			LCD_String_xy(2,4,chuoi);
			while (DOWN == 1){};
		}
		if(B1 == 1){
			L1 = 1;
			for(i = T;i>0;i--){
				sprintf(arr,"%d",i);
				LCD_String_xy(0,7,arr);
				if (i>=10) LCD_String_xy(0,9,"s");
				if(i>0 && i<10){
				LCD_String_xy(0,8,"s  ");
				}
			delayMs(1000);
			}
			if (i == 0) LCD_String_xy(0,7,"OFF");
			L1 = 0;
		}
		if(B2 == 1){
			L2 = 1;
			for(i = T;i>0;i--){
				sprintf(arr,"%d",i);
				LCD_String_xy(1,7,arr);
				if (i>=10) LCD_String_xy(1,9,"s");
				if(i>0 && i<10){
				LCD_String_xy(1,8,"s  ");
				}
				delayMs(1000);
			}
			if (i == 0) LCD_String_xy(1,7,"OFF");
			L2 = 0;
		}
	}
}
