	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	AREA hex_bcd,CODE,READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	LDR R0,=VAL
	LDR R1,[R0]
	LDR R0,=RES
	MOV R2,#8
LOOP
	AND R4,R1,#0xF
	ADD R4,#0x30
	STR R4,[R0],#4
	LSR R1,#4
	SUBS R2,R2,#1
	BNE LOOP
STOP
	B STOP
VAL	DCD 0x12345678
	AREA mydata,DATA,READWRITE
RES DCD 0,0,0,0,0,0,0,0
	END