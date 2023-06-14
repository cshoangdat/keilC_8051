btn_on EQU P3.2
btn_off EQU P3.3
led EQU P2.1

org 000h
jmp main

org 003h
	setb led
	reti
org 013h
	clr led
	reti

org 100h
	main:
	clr btn_on
	clr btn_off
	clr led
	
	setb IT0
	setb IT1
	setb EA
	setb EX0
	setb EX1
	
	loop:
	jmp loop
end