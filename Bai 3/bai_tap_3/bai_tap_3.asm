org 000h
	clr p2.0
	clr p2.1
	clr p1.0
	clr p1.1
	
	main:
	jb p2.0,led1
	jb p2.1,led2
	jmp lb_next
	
	led1:
	cpl p1.0
	jb p2.0,$
	jmp lb_next
	
	led2:
	cpl p1.1
	jb p2.1,$
	jmp lb_next
	
	lb_next:
	call delay
	jmp main
	
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
	end