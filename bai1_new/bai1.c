#include <REGX52.H>
#include "delay.h"

sbit B1 = P3^2;
sbit B2 = P3^3;
sbit EN = P3^4;
sbit STOP = P3^5;
sbit L1 = P2^0;
sbit L2 = P2^1;
sbit lS = P2^2;

void setup(){
	B1 = 0;
	B2 = 0;
	EN = 0;
	STOP = 0;
	IT0=1;
	IT1=1;
	EA=1;
	EX0=0;
	EX1=0;
}

void ISR_INT0(void) interrupt 0
{
		L1=!L1;
}

void ISR_INT1(void) interrupt 2
{
		L2=!L2;
}

void main(void){
	L1 = 0;
	L2 = 0;
	LS = 0;
	setup();
	while(1)
	{
		if(EN == 1){
			LS = 1;
			L1 = 0;
			L2 = 0;
			EX0 = 1;
			EX1 = 1;
		}
		if(STOP == 1){
			LS = 0;
			L1 = 0;
			L2 = 0;
			EX0 = 0;
			EX1 = 0;
		}
	}
}