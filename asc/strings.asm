assume cs:code,ds:data
data segment
	sird dd 12345678h,10293847h,15263748h
	len equ $-sird;legth in bytes
	sirw dw len dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax


	lea bx,byte ptr bx[6]
	mov ax,4c00h
	int 21h
code ends
end start