org 00h
	mov a, #0
	
	loop:
	inc a
	mov p1,a
	call delay
	cjne a,#100,loop
	jmp $

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
	
	