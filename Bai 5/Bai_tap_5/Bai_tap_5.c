#include <REGX52.H>
#include <rtx51tny.h>

sbit btn1 = P3^0;
sbit btn2 = P3^1;
sbit led1 = P1^4;
sbit led2 = P1^5;
sbit led3 = P1^6;

void delay(unsigned int t){
	int i,j;
	for(i = 0; i<t; i++)
	for(j = 0; j<123; j++){}
}

void setup(){
	btn1 = 0;
	btn2 = 0;
	led1 = 0;
	led2 = 0;
}

void loop(void) _task_ 1
{
	while(1){
	led3 = ~led3;
	delay(1000);
	}
}

void btn(void) _task_ 2
{
	while(1){
		if(btn1 == 1){
			led1 = ~led1;
			delay(500);
			while(btn1 == 1){
			};		
		}
		if(btn2 == 1){
			led2 = ~led2;
			delay(500);
			while(btn2 == 1){
			};		
		}
	}
}

void startup_task (void) _task_ 0
{
os_create_task (1); /* Create serial_io Task */
os_create_task (2); /* Create serial_cmds Task */

os_delete_task (0); /* Delete the Startup Task */
}
