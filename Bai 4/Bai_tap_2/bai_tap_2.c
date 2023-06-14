#include <REGX52.H>
#define LED P3
	
void delay(unsigned int t){
	int i,j;
	for (i = 0;i<t;i++)
	for (j = 0;j<123;j++){}
}

void main (void){
	int k;
	LED = 0;
	for (k = 0;k<100;k++)
	{
		LED = k;
		delay(500);
	}
}
