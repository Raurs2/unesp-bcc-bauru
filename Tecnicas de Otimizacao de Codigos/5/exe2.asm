n equ 90
r equ 91
i equ 92
mov A, 1

cmp A, n
jz acabo
call incrementa
inc A
acabo
    mov [r], A
    hlt
incrementa
    