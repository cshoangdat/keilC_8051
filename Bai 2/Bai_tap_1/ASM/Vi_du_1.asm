x data 30h
y equ 31h
z equ  32h

org 00h
mov x, #2
mov y, #3
mov a, x
add a, y
mov z, a
jmp $
	end