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
	ldr r9,=temp
	ldr r0,=src
	ldr r1,[r0]
	mov r2,#0
up	
	cmp r1,#0xA
	bcc store
	sub r1,#0xA
	add r2,#1
	b up
store
	strb r1,[r9],#1
	mov r1,r2
	mov r2,#0
	cmp r1,#0xA
	bcs up
	strb r1,[r9]
	;bl pack

	ldr r7,=temp
	ldr r1,[r7]
	ldr r9,=dest
	mov r3,#0xF
	mov r4,#0
	mov r5,#4
bch	
	and r6,r1,r3
	lsl r3,#4
	lsr r1,#4
	orr r4,r6
	subs r5,#1
	bne bch
	str r4,[r9]
stop
	b stop
src dcd 0x12B
	AREA mydata,DATA,READWRITE
temp dcd 0
dest dcd 0
	END