section .data
	msg DB 'assembly' ; Initialize string
	len EQU $ - msg ; Extract length
	newLine DB 10 ; Store '\n' character

section .text
global _start

_start:
	MOV esi,0 ; Set loop counter to 0

_loop:
	CMP esi,len ; Compare counter with length
	JGE _exit ; If Counter is greater than length, exit

	MOV eax,4 ; Call system write
	MOV ebx,1
	LEA ecx,[esi + msg] ; Write each character by offseting by the counter
	MOV edx,1 ; Number of bytes to write
	INT 0x80 ; Start Interupt

	MOV eax,4 ; Call system write
	MOV ebx,1
	LEA ecx,newLine ; Write '\n'
	MOV edx,1 ; Number of bytes to write
	INT 0x80 ; Start Interupt

	INC esi ; Increment counter
	JMP _loop ; Jump back to the start of the loop

_exit:
	MOV eax,1
	MOV ebx,0
	INT 0x80
