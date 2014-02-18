assume cs:code, ds:data
data segment
	s1 dw 1,2,3,4,5,6
	ls1 equ $-s1
	s2 dw 9,8,7
	ls2 equ $-s2
	s3 dw ls1+ls2 dup(23)

data ends

code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax

	mov cx,ls1
	mov si,offset s1
	mov di,offset s3
	cld
	begloop:
		LODSW
		STOSW
		dec cx
	loop begloop
	mov si,offset s2
	add si,ls2-2

	mov cx,ls2
	bl2:
		std
		LODSW
		cld
		STOSW
		dec cx
	loop bl2

	mov ax,4c00h
	int 21h
code ends
end start