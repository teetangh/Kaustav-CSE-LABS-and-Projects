	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	ALIGN
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
    LDR R5,=RESULT
	LDR R0,=NUM1
	LDR R1,=NUM2
    LDR R2,[R0]
    LDR R3,[R1]
    UMULL R6,R7,R3,R2
    STR R6,[R5]
	ADDS R5,R5,#4
    STR R7,[R5]
STOP
    B STOP
    ALIGN
NUM1 DCD 0x10000004
NUM2 DCD 0x54000000
    AREA mydata,DATA,READWRITE
RESULT DCD 0
    END