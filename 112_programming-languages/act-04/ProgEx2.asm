section .data
	msg DB 'gnimmargorp'
	len EQU $ - msg
    size EQU len - 1
	newLine DB 10

section .text
global _start

_start:
	MOV esi,size

_loop:
	CMP esi,0
	JL _exit

	MOV eax,4
	MOV ebx,1
	LEA ecx,[esi + msg]
	MOV edx,1
	INT 0x80

	MOV eax,4
	MOV ebx,1
	LEA ecx,newLine
	MOV edx,1
	INT 0x80

	DEC esi
	JMP _loop

_exit:
	MOV eax,1
	MOV ebx,0
	INT 0x80
