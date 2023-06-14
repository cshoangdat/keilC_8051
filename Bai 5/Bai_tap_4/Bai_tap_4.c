#include <REGX52.H>

sbit btn1 = P3^2;
sbit btn2 = P3^3;
sbit led1  = P1^4;
sbit led2 = P1^5;

void delay(unsigned int t){
	int i,j;
	for(i = 0; i<t; i++)
	for(j = 0; j<123; j++){}
}

void btn_setup (){
	btn1 = 0;
	btn2 = 0;
	
	IT0 = 1;
	IT1 = 1;
	EA = 1;
	EX0 = 1;
	EX1 = 1;
}

void ISR_INT0(void) interrupt 0{
	led1 = ~led1;
	delay(500);
}

void ISR_INT1(void) interrupt 2{
	led2 = ~led2 ;
	delay(500);
}

void main(void)
{
	led1 = 0;
	led2 = 0;
	btn_setup();
	while(1){}
}