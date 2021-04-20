	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=Value1
	LDR R1,[R0]		;R1 gets Value1
	LDR R0,=Value2
	LDR R2,[R0]		;R2 gets Value2
	SUBS R6,R1,R2	;R6 = R1 - R2
	LDR R3,=Result	;R3 points to Result	
	STR R6,[R3]		;Store subtraction result from R6 in R3(result array)
STOP
	B STOP
Value1 DCD 50
Value2 DCD 20
	ALIGN
	AREA mydata, DATA, READWRITE
Result DCD 0
	END