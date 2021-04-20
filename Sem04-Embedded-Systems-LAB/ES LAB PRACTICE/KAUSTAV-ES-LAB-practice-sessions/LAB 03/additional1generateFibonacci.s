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
	LDR R0,=FIB
	MOV R1,#0	;number1
	MOV R2,#1	;number2
	MOV R3,#8	;count of fibonacci
	
	STRB R1,[R0],#1

UP
	STRB R2,[R0],#1
	MOV R4,R2
	ADD R2,R1
	MOV R1,R4
	SUBS R3,#1
	BNE UP
	
STOP
	B STOP
	ALIGN
	AREA mydata,DATA,READWRITE
FIB DCD 0
	END