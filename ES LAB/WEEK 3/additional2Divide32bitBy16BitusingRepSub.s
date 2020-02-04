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
	LDR R0,=NUM
	LDR R1,=DEN
	LDR R2,=RESULT
	LDR R3,[R0] ;Storing Numerator
	LDR R4,[R1] ;Storing Denominator
	LDR R5,#0 ;Counter for Quotient
UP CMP R3,R4 ;Comparing Numerator and Denominator
	BCC NEXT
	SUBS R3,R4	;Remainder
	ADD R5,R5,#1 ;Quotient
	B UP
NEXT STR R3,[R2],#4
	STR R5,[R2]
STOP
	B STOP
NUM DCD 5
DEN DCD 2
	ALIGN
	AREA mydata,DATA,READWRITE
RESULT DCD 0
	END