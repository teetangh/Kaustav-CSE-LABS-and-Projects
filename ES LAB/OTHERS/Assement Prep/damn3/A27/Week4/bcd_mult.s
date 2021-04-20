	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	AREA bcd_mult,CODE,READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	LDR R0,=N1
	LDR R2,[R0]
	BL BCD_HEX
	MOV R9,R5
	LDR R0,=N2
	LDR R2,[R0]
	BL BCD_HEX
	MOV R10,R5
	MUL R9,R10
	BL HEX_BCD
	LDR R0,=RES
	LDR R9,=TEMP
	LDR R1,[R9]
	STR R1,[R0]
STOP
	B STOP
BCD_HEX
	MOV R1,R2
	MOV R3,#1
	MOV R5,#0
	MOV R4,#10
	MOV R2,#0xF
LOOP
	AND R6,R1,R2
	MLA R5,R6,R3,R5
	MUL R3,R3,R4
	LSR R1,#4
	CMP R1,#0
	BNE LOOP
	BX LR
HEX_BCD
	LDR R6,=TEMP
	MOV R2,#0
	MOV R1,R9
UP1
	CMP R1,#0xA
	BCC STORE
	SUB R1,#0xA
	ADD R2,#01
	B UP1
STORE
	STRB R1,[R6],#1
	MOV R1,R2
	MOV R2,#0
	CMP R1,#0xA
	BCS UP1
	STRB R1,[R6]
	LDR R6,=TEMP
	LDR R0,[R6]
	MOV R2,#0xF
	MOV R3,#0
	MOV R4,#4
LOOP1
	AND R5,R0,R2
	LSL R2,#4
	LSR R0,#4
	ORR R3,R5
	SUBS R4,#1
	BNE LOOP1
	STR R3,[R6]
	BX LR
N1	DCD 0x5
N2	DCD 0x3
	AREA mydata,DATA,READWRITE
RES DCD 0
TEMP DCD 0
	END