;9. 
;A byte string S is given. Obtain the string D1 which contains all the positive 
;numbers of S and the string D2 which contains all the negative numbers of S.
;Exemple:
; S: 1, 3, -2, -5, 3, -8, 5, 0
; D1: 1, 3, 3, 5, 0
; D2: -2, -5, -8
assume cs:code,ds:data
data segment
	s db 1,3,-2,-5,3,-8,5,0
	len equ $-s
	d1 db len dup(?)
	d2 db len dup(?)
data ends
code segment
start:
	mov ax,data
	mov ds,ax

	mov bx,0
	mov di,0;index of d1
	mov si,0;index of d2
	repeat:
		mov al,s[bx]
		test al,80h
		jne negativ
			mov d1[di],al
			add di,1
			jmp sfif
		negativ:
			mov d2[si],al
			add si,1
		sfif:
		add bx,1
		cmp bx,len
	jb repeat

	mov ax,4c00h
	int 21h
code ends
end start
