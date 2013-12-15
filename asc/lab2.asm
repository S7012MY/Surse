ASSUME cs: code, ds:data     ;spunem asamblorului care sunt segmentele folosite de noi
 
data SEGMENT                
                             ;data - segmentul de date in care vom defini variabilele
m db 5
h db 190
yy db 94
d db 26
data ENDS
 
code SEGMENT                 ;code - numele segmentului de cod
start:
mov ax,data             ;adresa segmentului de date se copiaza in ax
mov ds,ax                    ;continutul lui ax se copiaza in ds
; .......
                             ;aici avem instructiunile programului nostru
;(yy+h)-m-(d+d)

mov al,yy ;al=94=5Eh
mov ah,0
mov bl,h
mov bh,0 ;bx=190=BEh

add ax,bx  ;ax=94+190=284=11Ch
mov bl,m
mov bh,0

sub ax,bx  ;ax=284-5=279=117h
mov bl,d
mov bh,0

mov cl,d
mov ch,0
add bx,cx  ;bx=26+26=52=34h

sub ax,bx  ;ax=279-52=227=E3

;........
mov ax,4C00h
int 21h                      ;finalul executiei programului
                            
code ENDS
END start