	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD	0x10001000
	DCD	Reset_Handler
	AREA addition, CODE, READONLY
	EXPORT Reset_Handler
	ENTRY
Reset_Handler
	MOV R0,#2
	MOV R1,#3
	ADD R2,R0,R1
	END