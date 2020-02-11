	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=NUM1
	LDR R1,=NUM2
	LDR R2,[R0]
	LDR R3,[R1]
	LDR R5,=GCD
	LDR R6,=LCM
UP CMP R2,R3
	BEQ EXIT
	BCS NEXT
	SUB R3,R3,R2
	B UP
NEXT SUB R2,R2,R3
	B UP
EXIT STR R2,[R5] ;GCD IS STORED IN R5
	LDR R9,[R0]
	MUL R7,R9,R3
	MOV R8,#0
LOOP CMP R7,R2 ;PERFORM R7 DIVIDED BY GCD WHICH IS R2
	BCC ST
	SUB R7,R7,R2
	ADD R8,#1
	B LOOP
ST STR R8,[R6]
STOP
	B STOP
NUM1 DCD 0X00000009
NUM2 DCD 0X00000003
	AREA data,DATA,READWRITE
GCD DCD 0
LCM DCD 0
	END
