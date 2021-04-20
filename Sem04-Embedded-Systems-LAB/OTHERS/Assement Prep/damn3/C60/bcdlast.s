
	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=NUM1
	LDR R1,=NUM2
	LDR R2,[R0]
	LDR R3,[R1]
	LDR R9,=DST
	LDR R10,=0x10
	MOV R6,#0
LOOP
	MOV R4,R2
	MOV R5,R3
	MOV R7,#0x0F
	MOV R8,#4
	AND R4,R7
	ADD R4,R6
	MOV R6,#0
	AND R5,R7
	BL ADDN;BL=STORES THE ADDRESS IN R14
	LSR R2,#4
	LSR R3,#4
	STR R6,[R9]
	SUBS R10,#1
	BNE LOOP

	LDR R5,=DST
	LDR R0,[R5]
	LDR R1,=0x0000000F
	MOV R2,#4
	MOV R3,#0
UP
	AND R4,R0,R1
	LSR R0,#4
	LSL R1,#4
	ORR R3,R4
	SUBS R2,#1
	BNE UP
STOP
	B STOP
ADDN
	ADDS R4,R5
	CMP R4,#0xA
	BCC STR
	SUBS R4,#0xA
	ADD R6,#1
STR
	STRB R4,[R9],#1
	BX R14
NUM1 DCD 0x00000039
NUM2 DCD 0X00000029
	AREA mydata,DATA,READWRITE
DST DCD 0
	END



	LDR R5,=DST
	LDR R0,[R5]
	LDR R1,=0x0000000F
	MOV R2,#4
	MOV R3,#0
	UP
AND R4,R0,R1
LSR R0,#4
LSL R1,#4
ORR R3,R4
SUBS R2,#1
BNE UP
STOP
B STOP
ADDN
ADDS R4,R5
CMP R4,#0xA
BCC STR
SUBS R4,#0xA
ADD R6,#1
STR
STRB R4,[R9],#1
BX R14
NUM1 DCD 0x00000039
NUM2 DCD 0X00000029
AREA mydata,DATA,READWRITE
DST DCD 0
END