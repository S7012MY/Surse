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

	mov cx, 0
	mov si,offset sird
	mov bx,0
	mov bp,len
	begLoop:
		lodsw
		mov dx,cx
		and dx,1
		jnz impar
			mov sirw[bp],ax
			sub bp,2
			jmp pas
		impar:
			mov sirw[bx],ax
			add bx,2
		pas:
		inc cx
		cmp cx,len
	jne begLoop

	mov ax,4c00h
	int 21h
code ends
end start