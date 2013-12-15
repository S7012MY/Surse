assume ds:data,cs:code

;a-word; b,c,d-byte
; (a*2+b/2)/(c-d)

data SEGMENT
a dw 2
b db 3
c db 6
d db 4
rez dd ?;(4+1)/2=2
doi dw 2
data ENDS

code SEGMENT
start:
mov ax,data
mov ds,ax
;....
mov al,c
mov ah,0
sub al,d
sbb ah,0
mov bx,ax;bx=c-d
mov al,b
mov ah,0
div doi
mov cx,ax;cx=b/2

mov ax,a
mul doi
add ax,cx
adc dx,0
div bx

;....
mov ax,4C00h
int 21h
code ENDS
END start