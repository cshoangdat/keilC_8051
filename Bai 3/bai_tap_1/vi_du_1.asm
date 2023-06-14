btn_on EQU P2.4
btn_off EQU P2.5
led EQU P2.1

org 00h
	clr btn_on
	clr btn_off
	clr led
	
	loop:
	jb btn_on, lb_on
	jb btn_off, lb_off
	jmp lb_next
	
	lb_on:
	setb led
	jmp lb_next
	lb_off:
	clr led
	lb_next:
	jmp loop
end
	