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
	LDR R0,=SRC ;Source
	MOV R1,#0 ;Sum
	MOV R3,#0 ;Carry
	MOV R4,#10 ;Counter
	LDR R5,=DST ;Destination
LOOP LDR R2,[R0]
	ADDS R1,R1,R2
	ADC R3,#0
	ADD R0,#4 ;Increment Pointer
	SUBS R4,#1 ;Decrement Counter
	BNE LOOP ;Loop 
	STR R1,[R5] ;Store Final Sum
	STR R3,[R5,#4] ;Store Fianl Carry
STOP
	B STOP
	ALIGN
SRC DCD 10,20,30,40,50,60,70,80,90,100
	AREA mydata,DATA,READWRITE
DST DCD 0
	END