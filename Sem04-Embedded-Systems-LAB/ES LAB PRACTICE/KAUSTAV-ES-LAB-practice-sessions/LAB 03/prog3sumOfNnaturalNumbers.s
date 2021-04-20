	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode , CODE , READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=VAL1
	LDR R1,[R0]
	MLA R2,R1,R1,R1
	LSR R2,#1
	LDR R3,=DST
	STR R2,[R3]
	
VAL1 DCD 5

STOP
	B STOP
	ALIGN
	AREA mydata,DATA,READWRITE
DST DCD 0
	END