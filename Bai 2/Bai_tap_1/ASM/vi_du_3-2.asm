org 00h
	mov a,#0

loop:
inc a
mov p1, a
call delay1s
cjne a,#5,loop
jmp $
		
	delay1s:
		mov R3,#5
		s1back:
		call delay200ms
		djnz r3, s1back
		ret
		
	delay200ms:
		mov r2,#200
		lap2: mov r1,#200
		lap1: 
		nop
		nop
		nop
		djnz r1,lap1
		djnz r2,lap2
		ret
		
end