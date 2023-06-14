org 00h
	mov dptr,#LED7
	mov a,#1
	movc a,@a+dptr
	mov p2,a
	
	mov a,#3
	movc a,@a+dptr
	mov p3,a
	jmp $

org 200h
	LED7:
	DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH,77H,7CH,39H,5EH,79H,71H

END