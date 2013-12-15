assume cs:code,ds:data
data segment
	src db 01011100b, 10001001b, 11100101b 
	len equ $-src
	dst db len dup(0)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax

	mov si, len-1
	mov di, offset dst

	std

	mov cx,len
	repeta:
		LODSB
		cld

		mov dl,0
		inv:
			shl dst[len-1],1
			shr al,1
			adc dst[len-1],0

			inc dl
			cmp dl,8
		jb inv
		mov al,dst[len-1]
		mov dst[len-1],0

		STOSB
		std
	loop repeta


	mov ax,4c00h
	int 21h
code ends
end start