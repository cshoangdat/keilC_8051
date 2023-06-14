#include <REGX52.H>

#define LED P1

void delay1MS(void)
{
	int j;
	for(j = 0;j<123;j++){}
}

void delayMS(unsigned int t){
	int i;
	for(i=0;i<t;i++)
	delay1MS();
}

void main (void)
{
	while(1){
		LED = 0xff;
		delayMS(200);
		LED = 0x00;
		delayMS(200);
	}
}