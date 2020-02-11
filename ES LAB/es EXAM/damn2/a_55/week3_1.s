AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R1,=VALUE1
	LDR R2,=VALUE2
	LDR R3,[R1]
	LDR R4,[R2]
	UMULL R5,R6,R3,R4
	LDR R7,=RESULT
	STR R5,[R7]
	ADD R7,#4
	STR R6,[R7]
STOP
	B STOP
VALUE1 DCD 0X123456
VALUE2 DCD 0XABCABC
	AREA data,DATA,READWRITE
RESULT DCD 0
	END