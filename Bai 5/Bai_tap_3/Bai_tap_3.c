#include <REGX52.H>

sbit btn1 = P3^0;
sbit btn2 = P3^1;
sbit led1 = P1^4;
sbit led2 = P1^5;

void delay(unsigned int t){
	int i,j;
	for(i = 0; i<t; i++)
	for(j = 0; j<123; j++){}
}

void setup(){
	btn1 = 0;
	btn2 = 0;
	led1 = 0;
	led2 = 0;
}

void main(void){
	setup();
	while(1){
	if(btn1 == 1){
		led1 = ~led1;
		delay(500);
		while(btn1 == 1);		
}
	if(btn2 == 1){
		led2 = ~led2;
		delay(500);
		while(btn2 == 1);		
	}
}
}
