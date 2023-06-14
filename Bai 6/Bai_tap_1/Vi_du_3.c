#include <REGX52.H>
sbit led = P2^1;

void delay100us(){
	TMOD = 0x20;
	TH1 = 0x9C;
	TR1 = 1;
	while(TF1 == 0);
	TR1 = 0;
	TF1 = 0;
}

void main(void)
{
	while(1)
	{
		led =!led;
		delay100us();
	}
}