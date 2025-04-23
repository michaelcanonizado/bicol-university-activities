section .data
	msg DB 'gnimmargorp' ; Initialize string
	len EQU $ - msg ; Extract length
    size EQU len - 1 ; Offset length by 1
	newLine DB 10 ; Store '\n'

section .text
global _start

_start:
	MOV ecx,size ; Move size to the counter

_loop:
	CMP ecx,0 ; Exit loop if counter reaches 0
	JL _exit

    PUSH ecx ; Store counter

	MOV eax,4 ; Call system write
	MOV ebx,1
	LEA ecx,[ecx + msg] ; Offset string by the counter
	MOV edx,1 ; Number of bytes to write
	INT 0x80 ; Start interupt

	MOV eax,4 ; CAll system write
	MOV ebx,1
	LEA ecx,newLine ; Print '\n'
	MOV edx,1 ; Number of bytes to write
	INT 0x80 ; Start interupt

    POP ecx ; Retrieve counter

	DEC ecx ; Decrement counter
	JMP _loop ; Go back at the start of the loop

_exit:
	MOV eax,1
	MOV ebx,0
	INT 0x80
