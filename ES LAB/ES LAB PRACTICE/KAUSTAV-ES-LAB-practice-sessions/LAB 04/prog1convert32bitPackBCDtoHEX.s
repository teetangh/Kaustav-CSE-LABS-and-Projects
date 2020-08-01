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
	LDR R0,=NUM		;Number itself address
	LDR R6,=RESULT	;Result	
	LDR R1,[R0]		;Number itslef
	MOV R2,#0		;Current Sum
	MOV R4,#1		;Units,Tens,hundreds,thousands...
	MOV R5,#10		;place changer
LOOP
	AND R3,R1,#0x0F	;Bitmasking the last digit	
	MLA R2,R3,R4,R2	;Storing the temporary current sum in R2
	MOVS R1,R1,LSR #04	;After using the last digit,moving on to the next digit
	MUL R4,R4,R5	;Current digit place multiplier in R4 which is multiplied by 10 everytime
	BNE LOOP
	
	STR R2,[R6]	;Storing the answer in R6	
	
STOP
	B STOP
	ALIGN
NUM DCD 0x00001299
	AREA mydata,DATA,READWRITE
RESULT DCD 0
	END