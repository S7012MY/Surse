ASSUME cs: code, ds:data     ;spunem asamblorului care sunt segmentele folosite de noi
 
data SEGMENT                
                             ;data - segmentul de date in care vom defini variabilele
m db 5
h db 190
yy db 94
d db 26
aux dw ?
ddd dw ?
data ENDS
 
code SEGMENT                 ;code - numele segmentului de cod
start:
mov ax,data             ;adresa segmentului de date se copiaza in ax
mov ds,ax                    ;continutul lui ax se copiaza in ds
; .......
                             ;aici avem instructiunile programului nostru
;(yy+h)-m-(d+d)

mov al,yy ;al=94=5Eh
cbw
mov aux,ax;aux=5Eh
mov al,h;al=190=BEh
cbw ;ax=FFBEh 
add aux,ax;aux=5Eh+FFBEh=1001Ch overflow
mov al,m;al=5
cbw
sub aux,ax;aux=17h
mov al,d;al=1Ah
cbw
add ax,ax;ax=34h
sub aux,ax;aux=17h-34h=FFE3h

;........
mov ax,4C00h
int 21h                      ;finalul executiei programului
                            
code ENDS
END start
