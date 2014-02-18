assume cs:code,ds:data
data segment
	a dd 12345678h
data ends
code segment
start:

	mov ax,data
	mov ds,ax
	xchg ds,data

	mov bx,02 lt 20
	mov bx,offset ax
	;lea ax,bx

	mov ax,4c00h
	int 21h
code ends
end start