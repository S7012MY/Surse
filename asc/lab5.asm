;Dandu-se 4 octeti, sa se obtina in AX suma numerelor intregi reprezentate
;de bitii 4-6 ai celor 4 octeti

assume cs:code,ds:data
data segment
        a db 01010111b
        b db 01010111b
        c db 01010111b
        d db 01010111b
data ends

code segment
start
        mov ax,data
        mov ds,ax

        mov ax,0
        mov bl,01110000b ;b va fi masca
        mov cl,4; pentru shift

        and a,bl
        shr a,cl

        and b,bl
        shr b,cl

        and c,bl
        shr c,cl

        and d,bl
        shr d,cl


        add al,a
        add al,b
        add al,c
        add al,d

        mov ax,4c00h
        int 21h
code ends
end start