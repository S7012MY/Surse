assume cs:code
code segment public
	public com_pref
	com_pref:
		;receives in si and di the offset of the strings which have to be compared
		lp:
			mov bl,byte ptr[si]
			cmp bl,byte ptr [di]
			jne ending
			mov dx,[si]
			mov ax,0200h
			int 21h
			inc si
			inc di
		jmp lp
		ending:
	ret
code ends
end