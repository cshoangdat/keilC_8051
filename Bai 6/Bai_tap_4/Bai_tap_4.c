#include <REGX52.H>
sbit btnOn = P1^2;
sbit btnOff = P1^3;
sbit motor1 = P1^4;
sbit motor2 = P1^5;
unsigned int dcount = 0;
void ISR_timer0() interrupt 1
{
	TH0 = 0x3C;
	TL0 = 0xB0;
	dcount++;
}

void delay50MS(unsigned int t){
	TMOD = 0x01;
	TH0 = 0x3C;
	TL0 = 0xB0;
	IE = 0x82;
	dcount = 0;
	TR0 = 1;
	while(dcount <t);
	IE = 0;
	TR0 = 0;
}

void setup(){
	motor1 = 0;
	motor2 = 0;
	btnOn = 0;
	btnOff = 0;
}

void main (void){
	int i;
	setup();
	if(btnOn == 1){
		motor1 = 1;
		motor2 = 0;
		for(i = 0;i<100;i++){
			delay50MS(1);
			if(btnOff == 1) {break;}
		}
		motor1 = 0;
	}
	if(btnOff == 1)
		motor1 = 0;
		motor2 = 0;
}
