#include <REGX52.H>
#include "delay.h"
#include "dht11.h"

void main(void)
{
	unsigned char res;
	while(1)
	{
		res = dht_read();
		P2 = temp;
		P3 = humi;
		delayMs(100);
	}
}