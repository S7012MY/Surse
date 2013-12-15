; Dandu-se doua siruri de octeti sa se calculeze toate pozitiile unde al
;doilea sir
;apare ca subsir
; in primul sir.

; Ex: sir1: 2,2,3,7,5,10,2,3,4,5
;    sir2: 2,3
;    poz: 1,6


assume cs:code, ds:data
;10
data segment

        sir1        db        2,2,3,7,5,10,2,3,4,5
        l1        EQU        $-sir1
        sir2        db        2,3
        l2        EQU        $-sir2
        sir3        dw        10 dup (?)
        poz        dw        ?
        var        dw        ?
;20
data ends

code segment
start:

        mov ax, data
        mov ds, ax
        mov si, 0
        mov di, 0
;30        mov es, ax
        mov cx, l1
        jcxz final

        repeta:
                lodsb
                mov bx, 0
                mov dl, sir2[bx]
                sub si,1
                mov poz, si
                mov var, l2
;40                cmp al, dl
                jne repeta

                egal:
                        cmp var,0
                        je save
                        lodsb
                        inc bx
                        mov dl, sir2[bx]
                        cmp al,dl        ; NU COMPARA CUM TREBUIE

;50                        jnz repeta

                        save:
                                mov ax, poz
                                mov sir3[di], ax
                                inc di
                        cmp var, 0
                        dec var
                        jne egal

        loop repeta

        final:
        mov ax, 4c00h
        int 21h

code ends
end start
