Inicio   EQU   100
Final    EQU   119

         MOV   A, Inicio
         MOV   B, A

Repete
         MOV   A, 1
         MOV   [B], A
         INC   B
         
         MOV   A, B
         CMP   A, Final
         JBE   Repete
         
         HLT
         END
