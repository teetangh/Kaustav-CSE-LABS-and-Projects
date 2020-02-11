AREA RESET , DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10000000
	DCD Reset_Handler
	AREA MYCODE, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=NUM
	LDR R1,=DEN
	MOV R2,#0
	LDR R3,[R0]
	LDR R4,[R1]
	LDR R5,=QUO
	LDR R6,=REM
LOOP
	CMP R3,R4
	BLT NEXT
	SUB R3,R4
	ADD R2,#1
	B LOOP
NEXT
	STR R2,[R5]
	STR R3,[R6]
STOP
	B STOP
NUM DCD 18
DEN DCD 7
	AREA MYDATA, DATA, READWRITE
QUO DCD 0
REM DCD 0
	END