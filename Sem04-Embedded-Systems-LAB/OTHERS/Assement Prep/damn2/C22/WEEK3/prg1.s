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
	LDR R1,=VALUE1
	LDR R2,=VALUE2
	LDR R6,[R1]
	LDR R7,[R2]
	UMULL R3,R4,R6,R7
	LDR R5,=RESULT
	STR R4,[R5]
	ADD R5,#4
	STR R3,[R2]
STOP
	B STOP
VALUE1 DCD 0x54000000
VALUE2 DCD 0x10000004
	AREA data,DATA,READWRITE
RESULT DCD 0
	END