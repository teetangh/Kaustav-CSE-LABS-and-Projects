	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R1,=VAL1
	LDR R2,=VAL2
	LDR R3,=DST
	MOV R4,#0
	MOV R7,#4
	LDR R5,[R1]
	LDR R6,[R2]
UP	ADDS R5,R4
	MOV R4,#0
	ADC R4,#0
	ADDS R5,R6
	ADC R4,#0
	STR R5,[R3],#4
	ADD R1,#4
	ADD R2,#4
	SUBS R7,#1
	BNE UP
	STR R4,[R3]
STOP
	B STOP
	ALIGN
VAL1 DCD 1,2,3,4
VAL2 DCD 3,1,4,2
	AREA mydata,DATA,READWRITE
DST DCD 0
	END