#include <REGX52.H>

sbit btn1ON = P2^0;
sbit btn2ON = P2^1;
sbit btn3ON = P2^2;
sbit btn4ON = P2^3;
sbit btn1OFF = P2^4;
sbit btn2OFF = P2^5;
sbit btn3OFF = P2^6;
sbit btn4OFF = P2^7;
sbit led1  = P1^0;
sbit led2 = P1^1;
sbit led3 = P1^2;
sbit led4 = P1^3;

void setup(){
	led1  = 0;
	led2  = 0;
	led3  = 0;
	led4 = 0;
	btn1ON = 0;
	btn2ON = 0;
	btn3ON = 0;
	btn4ON = 0;
	btn1OFF = 0;
	btn2OFF = 0;
	btn3OFF = 0;
	btn4OFF = 0;
	led1  = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
}

void loop(){
	while(1)
	{
		if(btn1ON == 1){
			led1 = 1;
			while (btn1ON == 1);
		}
			if(btn1OFF == 1){
			led1 = 0;
			while (btn1OFF == 1);
		}
			if(btn2ON == 1){
			led2 = 1;
			while (btn2ON == 1);
		}
			if(btn2OFF == 1){
			led2 = 0;
			while (btn2OFF == 1);
		}
			if(btn3ON == 1){
			led3 = 1;
			while (btn3ON == 1);
		}
			if(btn3OFF == 1){
			led3 = 0;
			while (btn3OFF == 1);
		}
			if(btn4ON == 1){
			led4 = 1;
			while (btn4ON == 1);
		}
			if(btn4OFF == 1){
			led4 = 0;
			while (btn4OFF == 1);
		}
	}
}

void main (void){
	setup();
	loop();
}