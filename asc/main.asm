assume cs:code,ds:data
;if there are more data segments with the name data they will be merged
data segment public
	;when we call the function for reading from int 21
	;we must provide the offset of the place where the maximum length is stored
	;on the next byte the function will put the number of bytes that were read and then the string
	maxLen1 db 12
	len1 db ?
	s1 db 12 dup(?)
	maxLen2 db 12
	len2 db ?
	s2 db 12 dup(?)
	maxLen3 db 12
	len3 db ?
	s3 db 12 dup(?)
data ends

code segment
;we declare the functions used by the program which are defined in external modules
;read_string receives in bx the argument for 0ah function and reads at offset bx+2 a string
extrn read_string:proc
;receives in si and di the offset of the strings and then prints on the string the common prefix
extrn com_pref:proc
start:
	mov ax,data
	mov ds,ax
	mov bx, offset maxLen1
	;using the call instruction (working like a jmp) we are calling the read string procedure
	call read_string
	mov bx, offset maxLen2
	call read_string
	mov bx, offset maxLen3
	call read_string

	mov si,offset s1
	mov di,offset s2
	call com_pref

	mov si,offset s1
	mov di,offset s3
	call com_pref

	mov si,offset s2
	mov di,offset s3
	call com_pref



	mov ax,4c00h
	int 21h
code ends
end start