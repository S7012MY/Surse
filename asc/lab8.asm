assume cs:code, ds:data
data segment
	msg db 'Name of the file: $'
	m2 db 'c1:$'
	m3 db 'c2:$'
	maxFileName db 12
	lFileName db ?
	fileName db 12 dup(?)
	c1 db ?
	c2 db ?
	buffer db 105 dup(?),'$'
	openErrorMsg db 'File does not exist.$'
	readErrorMsg db 'Can t read the file.$'
	newl db 10,13,'$'
	citite dw ?
data ends
code segment
start:
	mov ax,data
	mov ds,ax

	;print the string msg
	mov ah, 09h
	mov dx, offset msg
	int 21h

	;read the name of the file
	mov ah,0ah
	mov dx, offset maxFileName
	int 21h

	;print new line
	mov dx,offset newl
	mov ah,09h
	int 21h

	;transform into asciiz
	mov bl,lFilename
	mov bh,0
	mov fileName[bx],0

	;print the string m2
	mov ah, 09h
	mov dx, offset m2
	int 21h

	;print new line
	mov dx,offset newl
	mov ah,09h
	int 21h

	;read c1
	mov ah, 01h
	int 21h
	mov c1,al

	;print the string m3
	mov ah, 09h
	mov dx, offset m3
	int 21h

	;print new line
	mov dx,offset newl
	mov ah,09h
	int 21h

	;read c2
	mov ah,01h
	int 21h
	mov c2,al

	;print new line
	mov dx,offset newl
	mov ah,09h
	int 21h

	;open the file
	mov ah,3dh
	mov al,0
	mov dx,offset fileName
	int 21h

	jc openError
	mov bx,ax
	reading:
		mov ah,3fh
		mov dx,offset buffer
		mov cx,100
		int 21h
		jc readError
		
		mov cx,ax
		mov citite,ax
		;iterate through buffer
		mov si,offset buffer
		mov di,0
		buf:
			LODSB
			cmp al,c1
			jne aici
				mov al,c2
				mov buffer[di],al
			aici:
			add di,1
		LOOP buf

		mov bp,citite
		mov buffer[bp],'$'
		;print buffer
		mov ah,09h
		mov dx,offset buffer
		int 21h
		mov dx,citite
		cmp dx,100
	je reading

	jmp endPrg
	openError:
		mov ah, 09h
		mov dx, offset openErrorMsg
		int 21h
		jmp endPrg 

	readError:
		mov ah, 09h
		mov dx, offset readErrorMsg
		int 21h 

	endPrg:
		mov ax,4c00h
		int 21h
code ends
end start