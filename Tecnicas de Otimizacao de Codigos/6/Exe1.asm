Inicio   EQU   100
Final    EQU   109
Soma     EQU   50

         MOV   A, 0
         MOV   [Soma], A
         
         MOV   A, Inicio
         MOV   B, A
Repete
         MOV   A, [Soma]
         ADD   A, [B]
         INC   B
         MOV   [Soma], A
         
         MOV   A, B
         CMP   A, Final
         JBE   Repete
         
         HLT
         END
