assume cs:code,ds:data
data segment
	s1 db 1,2,3,4
	s2 db 5,6,7,8
	len equ s2-s1
	s3 db len dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	mov es,ax

	mov bx,0
	etic:
		mov cl, s1[bx]
		mov ax,bx
		and ax,1
		jnz impar
			add cl,s2[bx]
			jmp pas
		impar:
			sub cl,s2[bx]
		pas:
		mov s3[bx],cl
	inc bx
	cmp bx,len
	jne etic

	mov ax,4c00h
	int 21h
code ends
end start