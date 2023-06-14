#include <REGX52.H>

sbit led = P2^1;
unsigned char flag = 0;
unsigned char revData;

void serial_init(void)
{
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;
	
	EA = 1;
	ES = 1;
}

void serial_send(unsigned char x)
{
	SBUF = x;
	while (TI == 0)
	TI = 0;
}

void serial_ISR(void) interrupt 4
{
	if(RI == 1){
		revData = SBUF;
		RI = 0;
		
		flag = 1;
	}
}

void main (void)
{
	led = 0;
	serial_init();
	while(1)
	{
		if(flag == 1)
		{
			if(revData == '1') led = 1;
			else led = 0;
			serial_send('O');
			serial_send('K');
			
			flag = 0;
		}
	}
}