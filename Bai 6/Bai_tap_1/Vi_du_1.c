#include  <REGX52.H>
sbit led = P2^1;
void delay1MS(){
	TMOD = 0X01;
	TH0 = 0XFC;
	TL0 = 0X18;
	TR0 = 1;
	while(TF0==0);
	TR0 = 0;
	TF0 = 0;
}

void delay(unsigned int t){
	int i;
	for(i = 0; i <t; i++)
	delay1MS();
}

void main (void){
	while(1){
		led = !led;
		delay(500);
	}
}