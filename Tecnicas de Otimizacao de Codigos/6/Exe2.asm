         ORG   200
Inicio   DB    1
         DB    2
         DB    3
         DB    4
         DB    5
         DB    5
         DB    4
         DB    3
         DB    2
Final    DB    1

         ORG   80
Maior    DB    0 
Conta    DB    0       

         ORG   0
         MOV   A, Inicio
         MOV   B, A
         
         MOV   A, Final
         SUB   A, Inicio
         INC   A
         MOV   [Conta], A
Repete
         MOV   A, [Maior]
         CMP   A, [B]
         JNC   Continua
         MOV   A, [B]
         MOV   [Maior], A
Continua
         INC   B
         
         MOV   A, [Conta]
         DEC   A
         MOV   [Conta], A
         
         JNZ   Repete
         
         HLT
         END
