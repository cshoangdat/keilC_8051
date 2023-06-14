#include <REGX52.H>
sbit led = P1^1;
sbit btn1 = P3^2;
sbit btn2 = P3^3;
#define led7Seg P2
unsigned int dcount = 0;
unsigned int count,i,j;
unsigned int a;
unsigned char maled[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void ISR_timer0() interrupt 1
{
	TH0 = 0xB1;
	TL0 = 0xE0;
	dcount++;
}

void delay20MS(unsigned int t){
	TMOD = 0x01;
	TH0 = 0xB1;
	TL0 = 0xE0;
	IE = 0x82;
	dcount = 0;
	TR0 = 1;
	while(dcount <t);
	IE = 0;
	TR0 = 0;
}

void setup(){
	led = 0;
	btn1 = 0;
	btn2 = 0;
	led7Seg = 0;
}
	
void main(void){
	int time;
	setup();
	count = 0;
	while(1){
		led = ~led;
		for(i=1;i<=100;i++){
			delay20MS(1);
			time = i;
			
				if(btn1 == 1){
					if(time<50){
						for(j = 0;j<10;j+=2){
							led7Seg = maled[j];
								for(a = 1;a<=50;a++){
								delay20MS(1);
								if((btn1 == 1 || btn2 == 1) && j !=0){time = a; break;}
								}
							if(btn1 == 1 || btn2 == 1 && j !=0){break;}
							led7Seg = maled[j+1];
								for(a = 1;a<=50-time;a++){
								delay20MS(1);
								if(btn1 == 1 || btn2 == 1) {time = 50+a; break;}
								}
							if(btn1 == 1 || btn2 == 1) {break;}
							led = ~led;
								for(a = 1;a<=time;a++){
								delay20MS(1);
								if(btn1 == 1 || btn2 == 1) {time = 100-time+a;break;}
								}
							if(btn1 == 1 || btn2 == 1) {break;}
						}
					}
					else{
						for(j = 0;j<10;j+=2){
							led7Seg = maled[j];
								for(a = 1;a<=100-time;a++){
								delay20MS(1);
								if((btn1 == 1 || btn2 == 1) && j != 0) {time = a; break;}
								}
							if(btn1 == 1 || btn2 == 1 && j != 0) {break;}
							led = ~led;
								for(a = 1;a<=time-50;a++){
								delay20MS(1);
								if(btn1 == 1 || btn2 == 1) {time = 100-time+a;break;}
								}
							if(btn1 == 1 || btn2 == 1) {break;}
							led7Seg = maled[j+1];
								for(a = 1;a<=50;a++){
								delay20MS(1);
								if(btn1 == 1 || btn2 == 1) {time = 50+a; break;}
								}
							if(btn1 == 1 || btn2 == 1) {break;}
						}
					}
				}
			
				if(btn2 == 1){
					if(time<50){
						for(j = 9;j>=0;j-=2){
							led7Seg = maled[j];
								for(a = 1;a<=50;a++){
								delay20MS(1);
								if((btn2 == 1 || btn1 ==1) && j !=9){time = a; break;}
								}
							if(btn2 == 1 && j !=9){break;}
							led7Seg = maled[j-1];
								for(a = 1;a<=50-time;a++){
								delay20MS(1);
								if(btn2 == 1 || btn1 == 1) {time = 50+a; break;}
								}
							if(btn2 == 1) {break;}
							led = ~led;
								for(a = 1;a<=time;a++){
								delay20MS(1);
								if(btn2 == 1 || btn1 == 1) {time = 100-time+a;break;}
								}
							if(btn2 == 1 || btn1 == 1) {break;}
						}
					}
					else{
						for(j = 9;j>=0;j-=2){
							led7Seg = maled[j];
								for(a = 1;a<=100-time;a++){
								delay20MS(1);
								if((btn2 == 1 || btn1 == 1) && j != 9) {time = a; break;}
								}
							if((btn2 == 1 || btn1 == 1) && j != 9) {break;}
							led = ~led;
								for(a = 1;a<=time-50;a++){
								delay20MS(1);
								if(btn2 == 1 || btn1 == 1) {time = 100-time+a;break;}
								}
							if(btn2 == 1 || btn1 == 1) {break;}
							led7Seg = maled[j-1];
								for(a = 1;a<=50;a++){
								delay20MS(1);
								if(btn2 == 1 || btn1 == 1) {time = 50+a; break;}
								}
							if(btn2 == 1 || btn1 == 1) {break;}
						}
					}
				}
				
			}
		}
	}	