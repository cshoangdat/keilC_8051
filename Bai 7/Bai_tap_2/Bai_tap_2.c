#include <REGX52.H>
#include <string.h>

sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
unsigned int dcount = 0;
unsigned long count = 0;
unsigned char flag = 0;
unsigned char revData;
unsigned char secondData;

void delayMS(unsigned int t)
{
	int i,j;
	for(i = 0;i<t;i++){
		for(j = 0;j<123;j++);
	}
}

void serial_init(void)
{
	TMOD = 0x20; //timer1,8bit,auto-reload
	TH1 = 0xFD; //9600 baud
	SCON = 0x50; //Serial: use timer1, receive enable
	TR1 = 1; //start timer 1
	
	EA = 1; //enable global interrupt
	ES = 1; //enable serial interrupt
}

void serial_send(unsigned char x)
{	
	SBUF = x;
	while (TI == 0); //TI = 1 finish send
	TI = 0; //need to clear TI flag
}

void serial_ISR(void) interrupt 4
{
	if(RI == 1){ //interrupt when receive data
		revData = SBUF; //revData to SBUF
		RI = 0; //need to clear RI flag
		
		flag = 1;
	}
}

//void serial_sendchuoi(char *a)
//{
//int i,n;
	//n = strlen(a);
	//for(i = 0;i<n;i++)
	//{
		//serial_send(a[i]);
	//}
//}

void sendsonguyen(unsigned long n){       // Ðinh nghia hàm gui 1 so nguyên       
if(n!=0)                                             //Truong hop so nguyên #0
 {
  unsigned char a[11];                        //mang chua các ký tu so sau khi tách 
  int i;                                      
  for(i=0;n>0;i++)                  //Vòng lap tách các chu so thành ký tu
  {
   a[i]=(n%10)+48;      //tách lay chu so hàng don vi,mã hóa ASCII
   n=n/10;                      //loai bo chu so hàng don vi
  }
  a[i]=NULL;                           //ký tu cuoi cùng cua chuoi phai là NULL
  for(i=strlen(a);i>=0;i--)              //Vòng lap gui lan luot tung ký tu lên,
  {                                                      //cho den khi het chuoi a[].
   serial_send(a[i]);                             //Gui lan luoi tung ki tu.         
  }
}
else serial_send('0');}

void main (void)
{
	unsigned char dem = '0';
	led1 = 0;
	led2 = 0;
	led3 = 0;
	serial_init();
	while(1)
	{
		if(flag == 1)
		{
			if(revData == '1' && secondData == 0) led1 = 1;
			if(revData == '2' && secondData == 0) led1 = 0;
			if(revData == '3' && secondData == 0) led2 = 1;
			if(revData == '4' && secondData == 0) led2 = 0;
			if(revData) count++;
			if(secondData==1)
			{
				for(dem='0'; dem < revData ; dem++)
				{
					led3=1;
					delayMS(500);
					led3=0;
					delayMS(500);						
				}
				secondData = 0;
			}
			if(revData=='5') secondData=1;
			serial_send(' ');
			sendsonguyen(count);
			serial_send(' ');
			flag = 0;
		}
	}
}