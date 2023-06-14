#include <REGX52.H>
#define LED P3

void delay(unsigned int t){
	int i,j;
	for(i = 0;i<t;i++)
	for(j = 0;j<123;j++){}
}

void reset(){
	LED = 0;
	delay(200);
}

void ledBlink(){
	int i;
	LED = 0;
	for(i = 0;i<10;i++){
	LED = 0xFF;
	delay(500);
	LED = 0x00;
	delay(500);
	}
	reset();
}

void ledShiftLeftRight(){
	int i,j;
	LED = 0x01;
	delay(500);
	for(i = 0;i<7;i++){
	LED = LED<<1;
	delay(500);
	}
	if(LED == 0x80){
		for(j = 0;j<7;j++){
		LED = LED>>1;
		delay(500);
		}
	}
}

void ledLightUpRighttoLeft(){
	int i;
	for(i = 0;i<7;i++){
	LED =(LED<<1)|1;
	delay(500);
	}
	reset();
}

void ledLightUpLefttoRight(){
	int i;
	LED = 128;
	delay(500);
	for(i = 0;i<7;i++){
	LED = (LED>>1)|128;
	delay(500);
	}
	reset();
}

unsigned char maled[] = {24,60,126,255,0,129,195,231,255};

void LedLightOuttoIn(){
	int i;
	for(i = 0;i<9;i++){
	LED = maled[i];
	delay(500);
	}
	reset();
	
}

unsigned char a = 0;
unsigned char b = 1;

void LedsangdonLefttoRight(){
	int i,j;
	LED = 0;
	for(i = 8;i>0;i--){
		for(j = i;j>0;j--)
		led = b|a;
		b = b<<1;
		delayMS(200);
	}
	a = LED;
	b = 1;
}

void main(void){
ledBlink();
LedsangdonLefttoRight();
ledShiftLeftRight();
ledLightUpRighttoLeft();
ledLightUpLefttoRight();
}