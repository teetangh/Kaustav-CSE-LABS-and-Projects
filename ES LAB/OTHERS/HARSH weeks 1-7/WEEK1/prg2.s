	AREA RESET, DATA, READONLY
	EXPORT __Vectors1         
__Vectors1
	DCD 0X10001000
	DCD Reset_Handler1
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler1
Reset_Handler1
	MOV R0,#5
	MOV R1,#3
	MOV R2,R0
	MOV R0,R1
                       	MOV R1,R2
	END