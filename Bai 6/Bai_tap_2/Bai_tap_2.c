#include <REGX52.H>
sbit Pin_out = P3^1;
unsigned int dcount = 0;

void ISR_timer0() interrupt 1
{
	TH0 = 0xFC;
	TL0 = 0x18;
	dcount++;
}

void delayMS(unsigned int t){
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0x18;
	IE = 0x82;
	dcount = 0;
	TR0 = 1;
	while(dcount <t);
	IE = 0;
	TR0 = 0;
}

void main(void){
	while(1){
		Pin_out = !Pin_out;
		delayMS(50);
	}
}
	