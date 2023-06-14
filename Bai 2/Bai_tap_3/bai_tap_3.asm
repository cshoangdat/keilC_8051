org 00h
	main:
	call LedBlink
	mov a,#1
	call oneLedShiftLeft
	call oneLedShiftRight
	call LedBlinkRighttoLeft
	call LedBlinkLefttoRight
	mov dptr, #Maled
	call LedBlinkIntoOuttoIn
	mov dptr, #Led1
	call LedLightupRighttoLeft
	mov dptr, #Led2
	call LedLightupLefttoRight
	jmp main
	
ledBlink:
	mov p1,#0
	call delay
	mov p1,#255
	call delay
	inc r0
	cjne r0,#10,ledBlink
ret

oneLedShiftLeft:
	mov p1,a
	rl a
	call delay
	cjne a,#128,oneLedShiftLeft
	mov p1,a
ret

oneLedShiftRight:
	rr a
	call delay
	mov p1, a
	cjne a,#1,oneLedShiftRight
	mov p1,a
ret

LedBlinkRighttoLeft:
	setb c
	rlc a
	call delay
	mov p1,a
	cjne a,#11111111B,LedBlinkRighttoLeft
	call delay
	call reset
ret

LedBlinkLefttoRight:
	rrc a
	call delay
	mov p1,a
	cjne a,#11111111B,LedBlinkLefttoRight
	call delay
	call reset
ret

LedBlinkIntoOuttoIn:
	mov a,r0
	movc a,@a+dptr
	mov p1,a
	call delay
	inc r0
	cjne r0,#12,LedBlinkIntoOuttoIn	
	call reset
ret

LedLightupRighttoLeft:
	mov a,r0
	movc a,@a+dptr
	mov p1,a
	call delay
	inc r0
	cjne a,#255,LedLightupRighttoLeft
	call reset
ret

LedLightupLefttoRight:
	mov a,r0
	movc a,@a+dptr
	mov p1,a
	call delay
	inc r0
	cjne a,#255,LedLightupLefttoRight
	call reset
ret

reset:
	mov a,#0
	mov r0,#0
	mov p1,a
ret

delay:
	mov r1,#10
	lap1:
	mov r2, #100
	lap2:
	mov r3, #100
	djnz r3,$
	djnz r2,lap2
	djnz r1,lap1
ret

	Led1:
	DB 80H,40H,20H,10H,8H,4H,2H,1H
	DB 81H,41H,21H,11H,9H,5H,3H
	DB 83H,43H,23H,13H,11,7H
	DB 87H,47H,27H,17H,15
	DB 8FH,4FH,2FH,1FH
	DB 9FH,5FH,3FH
	DB 191,7FH
	DB 255
	
	Led2:
	DB 1,2,4,8,16,32,64,128
	DB 81H,82H,84H,88H,90H,160,192
	DB 193,194,196,200,208,224
	DB 225,226,228,232,240
	DB 241,242,244,248
	DB 249,250,252
	DB 253,254
	DB 255
	
	Maled:
	DB 18H,3CH,7EH,255,0,81H,195,231,255
end
