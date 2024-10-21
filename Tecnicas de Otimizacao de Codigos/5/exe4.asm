N   equ 100
M   equ 101
S   equ 102

    mov A, 0
    mov A, [N]
    add A, [M]
    cmp A, 50
    jc salta1
    cmp A, 100
    jnc salta2
    mov [S], A
    hlt
salta1
    mov A, 50
    mov [S], A
    hlt
salta2
    mov A, 100
    mov [S], A
    hlt
    


    
