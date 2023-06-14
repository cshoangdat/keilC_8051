#include <REGX52.H>

sbit btnON = P2^4;
sbit btnOFF = P2^5;
sbit led  = P2^1;
void main (void){
	led  = 0;
	btnON = 0;
	btnOFF = 0;
	while(1)
	{
		if(btnON == 1){
			led = 1;
			while (btnON == 1);
		}
			if(btnOFF == 1){
			led = 0;
			while (btnOFF == 1);
		}
	}
}