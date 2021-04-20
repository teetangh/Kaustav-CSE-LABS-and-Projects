	AREA RESET, DATA, READONLY
		EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler

	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler	
Reset_Handler
	LDR R5,=DST
	LDR R6,=NUM
	LDR R0,[R6]
	MOV R9,#8
LOOP
	AND R1,R0,#0x0F
	ORR R1,R1,#0x30
	STR R1,[R5],#4
	LSR R0,#4
	MOV R1,R0
	SUBS R9,#1
	BNE LOOP
STOP
	B STOP
NUM DCD 0x19587658
	AREA MYDATA, DATA, READWRITE
DST DCD 0
	END