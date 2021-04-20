	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=SRC
	
	
	mov r4,#5
	mov r5,#0
UP  mul r6,r4,r5
    str r6,[r0],#4
	add r5,#1
	cmp r5,#10
	bcc UP 
	sub r0,#40
LOOP
	ldr r3,[r0],#4
	str r3,[r1],#4
	subs r2,#1
	bne LOOP
STOP
    b STOP

	AREA mydata,DATA,READWRITE
SRC dcd 1,2,3,4,5,6,7,8,9,10
DEST dcd 0
	end