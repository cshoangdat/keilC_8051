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
	setb p1.0
	clr p1.1
	
	setb IT0
	setb IT1
	setb EA
	setb EX0
	setb EX1
	
	led1:
	cpl p1.0
	call delay
	ret
	
	led2:
	cpl p1.1
	call delay
	ret
	
delay:
	mov r1,#10
	lap1:
	mov r2, #100
	lap2:
	mov r3, #200
	djnz r3,$
	djnz r2,lap2
	djnz r1,lap1
ret
	end