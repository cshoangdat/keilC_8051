#include <REGX52.H>
#define LED P3
unsigned char sangdon[] = {0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF};
	void delayMS(unsigned int t){
	int i,j;
		for(i = 0;i<t;i++)
		for(j = 0;j<123;j++){}
	}
	void sangdon_cach01(){
	int i;
		for(i = 0;i<9;i++){
		LED = sangdon[i];
		delayMS(200);
		}
	}
	void sangdon_cach02(){
	int i;
		LED = 0;
		delayMS(200);
		for(i=0;i<8;i++){
		LED =(LED<<1)|1;
		delayMS(200);
		}
	}
	
	void main(void){
	while(1)
		sangdon_cach02();
	}