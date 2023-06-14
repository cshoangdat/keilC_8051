#include <REGX52.H>

sbit btnON = P3^2;
sbit btnOFF = P3^3;
sbit led  = P2^1;

void btn_setup (){
	btnON = 0;
	btnOFF = 0;
	
	IT0 = 1;
	IT1 = 1;
	EA = 1;
	EX0 = 1;
	EX1 = 1;
}

void ISR_INT0(void) interrupt 0{
	led = 1;
}

void ISR_INT1(void) interrupt 2{
	led = 0 ;
}

void main(void)
{
	led = 0;
	btn_setup();
	while(1){}
}