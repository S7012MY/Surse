assume cs:code,ds:data
data segment public
	maxLen db 5
	len db ?
	number db 5 dup(?)
	zec dw 10
	zer dw '0'
data ends

code segment public
	public read_int
	read_int:
		;returns in bx the integer read from keyboard
		mov ax,0a00h
		mov dx,offset maxLen
		int 21h

		mov ax,0
		mov bx,0
		mov si,offset number
		cld
		begL:
			mul zec
			add al,number[bx]
			adc ah,0
			sub ax,zer
			add bx,1
			cmp bl,len
		jne begL
	ret
code ends
end