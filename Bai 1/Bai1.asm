;This is the demo blink led (P1) 
	ORG 0H
MAIN:
	MOV P1, #0AAH
	CALL DELAY1S
	MOV P1, #55H
	CALL DELAY1S
	JMP MAIN
	
DELAY1S:
		MOV R3, #5 
S1BACK:
		CALL DELAY200ms
		DJNZ R3, S1BACK
		RET ; ket thuc c.trinh con.
	
DELAY200ms:
		MOV R2, #200
LAP2: 	MOV R1, #200
LAP1: 	NOP ; lenh khong lam gi ca. Ton 1 chu ky may.
		NOP
		NOP
		DJNZ R1, LAP1 ; DECREASE, jump if not zero; 2 chu ky may.
		DJNZ R2, LAP2
		RET ; 200 X 200 X 5 chukymay(T=1/1MHz=1us) = 200ms. (xap xi) 
		
END