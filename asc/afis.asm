assume ds:data, cs:code
data segment
number db 67
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	
	mov al,number
	mov ah,0
	mov cl,10
	repe:
		div cl

		add ah,'0'
		mov dl,ah
		mov ah,02h
		int 21h

		mov ah,0

		cmp ax,0
	jg repe

	mov ax,4c00h
	int 21h

code ends
end start

