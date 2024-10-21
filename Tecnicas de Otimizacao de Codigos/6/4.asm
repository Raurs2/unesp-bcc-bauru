Inicio   EQU   100
Final    EQU   101
Valor    EQU   130
media    EQU   131
result   EQU   132
         MOV   A, 0
         MOV   [Valor], A
         mov [media], A
        mov [result], A

         MOV   A, [Inicio]
         MOV   B, A

Repete
         
         MOV   A, [B]
         ADD A, [Valor]
         MOV [Valor], A

         MOV A, 1
         ADD A, [media]
         mov [media], A

         INC   B
         MOV   A, B
         CMP   A, [Final]
         JBE   Repete

subb
        mov A, [Valor]
        SUB A, [media]
        JBE acabar
        mov [Valor], A
        mov A, 1
        ADD A, [result]
        mov [result], A
        ja subb

acabar
         HLT
         END
