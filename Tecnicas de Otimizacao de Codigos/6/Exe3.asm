          ORG   100
Vet          
EndInicio DB    160
EndFinal  DB    179
N         DB    10
Conta     DB    0
ContaMenores DB 0

          ORG   160
          DB    1
          DB    1
          DB    10
          DB    1
          DB    10
          DB    1
          DB    10
          DB    1
          DB    10
          DB    1
          DB    10
          DB    1
          DB    11
          DB    1
          DB    11
          DB    1
          DB    12
          DB    1
          DB    12
          DB    1

         ORG   0
         MOV   A, [EndInicio]
         MOV   B, A
         
         MOV   A, [EndFinal]
         SUB   A, [EndInicio]
         INC   A
         MOV   [Conta], A
Repete
         MOV   A, [B]
         CMP   A, [N]
         JNC   SeMaioresOuIgualSalta
         MOV   A, [ContaMenores] ; ContaContaMenores++
         INC   A
         MOV   [ContaMenores], A
SeMaioresOuIgualSalta
         
         INC   B          ; B++
         
         MOV   A, [Conta] ; Conta--
         DEC   A
         MOV   [Conta], A
         JNZ   Repete
         
         HLT
         END
