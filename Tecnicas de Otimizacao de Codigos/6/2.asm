Inicio   EQU   100
Final    EQU   119
Valor    EQU   130

         MOV   A, 0
         MOV   [Valor], A

         MOV   A, Inicio
         MOV   B, A

Repete
         MOV   A, [Valor]
         MOV   [B], A
         INC   B
         
         ADD A, 1
         MOV [Valor], A

         MOV   A, B
         CMP   A, Final
         JBE   Repete
         
         HLT
         END
