#include <REGX52.H>

sbit DC01 = P1^1;
sbit DC02 = P1^2;
sbit DC03 = P1^3;

void main (void)
{
	DC01 = 1;
	DC02 = 0;
	DC03 = 1;
}