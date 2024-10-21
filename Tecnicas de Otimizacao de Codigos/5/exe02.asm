NN equ 90
RR equ 91

    mov A, 0
    mov [RR], A
    call func1
func1
    mov A, [NN]
    cmp A, 0
    jz para
    add A, [RR]
    mov [RR], A
    mov A, [NN]
    dec A 
    mov [NN], A
    call func1
para
    hlt