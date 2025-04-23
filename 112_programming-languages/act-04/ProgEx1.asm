section .data
	msg DB 'assembly' ; Initialize string
	len EQU $ - msg ; Extract length
	newLine DB 10 ; Store '\n' character

section .text
global _start


_start:
	MOV ecx,0 ; Set loop counter to 0

_loop:
	CMP ecx,len ; Compare counter with length
	JGE _exit ; If Counter is greater than length, exit

	PUSH ecx ; Store counter

	MOV eax,4 ; Call system write
	MOV ebx,1 ; stdout
	LEA ecx,[ecx + msg] ; Write each character by offseting by the counter
	MOV edx,1 ; Number of bytes to write
	INT 0x80 ; Start Interupt

	MOV eax,4 ; Call system write
	MOV ebx,1 ; stdout
	LEA ecx,newLine ; Write '\n'
	MOV edx,1 ; Number of bytes to write
	INT 0x80 ; Start Interupt

	POP ecx ; Retrieve counter

	INC ecx ; Increment counter
	JMP _loop ; Jump back to the start of the loop

_exit:
	MOV eax,1
	MOV ebx,0
	INT 0x80
