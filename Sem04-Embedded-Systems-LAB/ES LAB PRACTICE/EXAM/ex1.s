;Copyright Kaustav
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
	LDR R1,=NUM1
	LDR R2,=SUM
	
	LDR R10,=DST
	
	LDR R3,[R1]		;r3 holds r1 value
	LDR R4,[R2]		;r4 holds r2 value
	
	MOV R5,#0	;Last Digit holder
	MOV R6,#0	;Remainder
	MOV R7,#0	; Current Sum
	
LOOP
	AND R5,R3,#0x01		;R5 is last digit or rem
	MUL R6,R5,R5		;R6 = R5^2
	MUL R6,R6,R5		;R6 = R5^3
	ADC R7,R7,R6		;R7 = R7 + R6
	;MLA R7,R6,R5,R7
	
	MOVS R3,R3,LSR #04	;Dividing the number by 10
	BNE LOOP
	
	LDR R3,[R1]	;Reloading the original nunmber
	
	CMP R7,R3	;Checking the if condition
	BEQ IFCONDITION
	BNE ELSECONDITION
	
IFCONDITION
	MOV R8,#0xFF
	STR R8,[R10]
	B EXIT
ELSECONDITION
	MOV R8,#0xAA
	STR R8,[R10]
	B EXIT
EXIT

STOP
	B STOP
	
	ALIGN
NUM1 DCD 153
SUM DCD 0
DST DCD 0
	END