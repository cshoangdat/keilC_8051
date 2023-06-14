org 00h
	clr p1.0
	clr p1.1
	clr p1.2
	clr p1.3
	clr p2.0
	clr p2.1
	clr p2.2
	clr p2.3
	clr p3.0
	clr p3.1
	clr p3.2
	clr p3.3
main:
	jb p2.0,led_1_on
	jb p3.0,led_1_off
	jb p2.1,led_2_on
	jb p3.1,led_2_off
	jb p2.2,led_3_on
	jb p3.2,led_3_off
	jb p2.3,led_4_on
	jb p3.3,led_4_off
jmp main

led_1_on:
setb p1.0
jmp main
led_2_on:
setb p1.1
jmp main
led_3_on:
setb p1.2
jmp main
led_4_on:
setb p1.3
jmp main

led_1_off:
clr p1.0
jmp main
led_2_off:
clr p1.1
jmp main
led_3_off:
clr p1.2
jmp main
led_4_off:
clr p1.3
jmp main