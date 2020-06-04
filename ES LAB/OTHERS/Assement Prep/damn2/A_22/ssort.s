	AREA RESET, CODE, READONLY
	EXPORT __Vectors 
__Vectors	
	DCD 0X10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR r0,=dst
l2	MOV r1,r0
	MOV r3,r0
	ADD r3,#1
	ADD r10,r9,#1
l1	LDRB r4,[r3]
	LDRB r7,[r1]
	cmp r4,r7
	bcs up
	MOV r1,r3
up	ADD r3,#1
	ADD r10,#1
	cmp r10,#10
	bne l1
	LDRB r2,[r0]
	LDRB r6,[r1]
	STRB r2,[r1]
	STRB r6,[r0]
	ADD r0,#1
	ADD r9,#1
	cmp r9,#9
	bne l2
stop
	b stop
	AREA mydata,DATA,READWRITE
dst dcd 0
	END