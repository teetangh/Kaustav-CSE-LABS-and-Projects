	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
		DCD 0X10001000
		DCD Reset_Handler
	AREA reverse, CODE, READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
		LDR R0,=SRC
		MOV R1,R0
		ADD R1,R1,#36
		MOV R2,#5
REVE
		LDR R3,[R0]
		LDR R4,[R1]
		STR R3,[R1]
		STR R4,[R0]
		ADD R0,R0,#0x00000004
		SUB R1,R1,#0x00000004
		SUBS R2,R2,#1
		BNE REVE
STOP
		B STOP
	AREA mydata,DATA,READWRITE
SRC DCD 0
	END