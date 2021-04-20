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
	mov r1,#5
	mov r2,#0
UP  mul r3,r2,r1
    str r3,[r0],#4
	add r2,#1
	cmp r2,#10
	bcc UP 
	sub r0,#40
	
	ldr r5,=size
	ldr r0,=SRC + (size-1)*4
	mov r6,r0
	sub r6,#(ol-1)*4
	add r6,#(size-1)*4
LOOP
	ldr r7,[r0],#-4
	str r7,[r6],#-4
	subs r5,#1
	bne LOOP
STOP
	b STOP
size equ 10
ol equ 2
	AREA mydata,DATA,READWRITE
SRC dcd 0
	end


