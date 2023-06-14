#include <REGX52.H>
#include "delay.h"
#include "LCD2004.h"

sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit led4 = P2^3;
sbit btn1 = P2^4;
sbit btn2 = P2^5;
sbit btn3 = P2^6;
sbit btn4 = P2^7;

void setup(){
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
	btn1 = 0;
	btn2 = 0;
	btn3 = 0;
	btn4 = 0;
	LCD_String_xy(0,0,"LED01: OFF");
	LCD_String_xy(1,0,"LED02: OFF");
	LCD_String_xy(2,0,"LED03: OFF");
	LCD_String_xy(3,0,"LED04: OFF");
}

void main(void)
{
	LCD_Init();
	setup();
	while(1){
	if(btn1 == 1) 
		{
		led1 =~led1;
		delayMs(50);
		if(led1 == 1) {LCD_String_xy(0,0,"LED01: ON ");}
		if(led1 == 0) {LCD_String_xy(0,0,"LED01: OFF");}
		while(btn1 == 1);
		}
	if(btn2 == 1) 
		{
		led2 =~led2;
		delayMs(50);
		if(led2 == 1) {LCD_String_xy(1,0,"LED02: ON ");}
		if(led2 == 0) {LCD_String_xy(1,0,"LED02: OFF");}
		while(btn2 == 1);
		}
	if(btn3 == 1) 
		{
		led3 =~led3;
		delayMs(50);
		if(led3 == 1) {LCD_String_xy(2,0,"LED03: ON ");}
		if(led3 == 0) {LCD_String_xy(2,0,"LED03: OFF");}
		while(btn3 == 1);
		}
	if(btn4 == 1) 
		{
		led4 =~led4;
		delayMs(50);
		if(led4 == 1) {LCD_String_xy(3,0,"LED04: ON ");}
		if(led4 == 0) {LCD_String_xy(3,0,"LED04: OFF");}
		while(btn4 == 1);
		}
		
	}
}