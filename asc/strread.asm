assume cs:code
code segment public
	;we declare our method public so that it  can be called from other modules
	public read_string
	read_string:
		;receives in bx the offset of the string which is read
		mov dx,bx
		mov ax,0a00h
		int 21h
		mov si,bx
		add si,2
		mov bl,byte ptr[bx+1]
		mov bh,0
		mov byte ptr [bx+si],0
	ret
code ends
end