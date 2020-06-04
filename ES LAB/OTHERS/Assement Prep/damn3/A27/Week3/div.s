	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	AREA div,CODE,READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	LDR R0,=VAL1
	LDR R1,=VAL2
	MOV R2,#0
	LDR R3,[R0]
	LDR R4,[R1]
LOOP
	CMP R3,R4
	BCS SKIP
	MOV R5,R3
	B STOP
SKIP
	SUB R3,R3,R4
	ADD R2,R2,#1
	B LOOP
STOP
	B STOP
VAL1	DCD 12
VAL2	DCD 5
	END