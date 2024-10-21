i       equ     200
f       equ     255
menor   equ     100
maior   equ     101

        mov     A, i
        mov     B, A

        mov     A, [B]
        mov     [menor], A
        mov     [maior], A
        inc     B

repet
        mov     A, [B]
        inc     B

        cmp     A, [menor] ;if A < menor menor = A c = 1
        jc troca1

        cmp     A, [maior] ;if A > maior maior = A c = 0 z = 0
        ja troca2

troca1
        mov [menor], A

        mov A, B
        cmp A, 0
        jnz repet

        hlt

troca2
        mov [maior], A

        mov A, B
        cmp A, 0
        jnz repet

        hlt
        end