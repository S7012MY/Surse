assume cs:code,ds:data
data segment
	d dw 81
	v dd 48,81,33,44,55
	len dw $-v
	;(a+a+b*c*100)/(a+10)
	;a,b,c-byte
	a db 23
	b db 23
	c db 23
	sut dw 100
data ends
code segment
start:
	mov ax,data
	mov ds,ax

	mov cx,3
	mov al,0
	begloop:
		mov ah,02h
		mov dl,1+'0'
		int 21h
	LOOP begloop


	mov ax,4c00h
	int 21h
code ends
end start