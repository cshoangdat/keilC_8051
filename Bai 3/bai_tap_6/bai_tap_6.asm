org 000h
	jmp main
	

org 003h
	call led1
	reti
	
org 013h
	call led2
	reti

org 100h
	main:
	clr p3.2
	clr p3.3
	clr p1.0
	clr p1.1
	
	setb IT0
	setb IT1
	setb EA
	setb EX0
	setb EX1
	
	loop:
	cpl p1.2
	call delay1s
	jmp loop
	
	led1:
	cpl p1.0
	ret
	
	led2:
	cpl p1.1
	ret
	
	delay1s:
		MOV R3,#10
	S1BACK:
		call delay100ms
		DJNZ R3, S1BACK
		RET		; ket thuc c.trinh con.	
		
	delay100ms:
	mov r4,#10
	lap1:
	mov r5, #50
	lap2:
	mov r6, #100
	djnz r6,$
	djnz r5,lap2
	djnz r4,lap1
	ret
end