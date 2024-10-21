;O valor máximo para n no AS.SIM é 5, pois 6 resultaria 720 (mais que um byte)

        ORG     90
n       DB      5
resMult DB      0
paMultM DB      0
paMultN DB      0
contMul DB      0
fat     DB      0

        ORG     0
        MOV     A,[n]
        MOV     [fat],A
LacFat
        MOV     A,[n]
        DEC     A
        MOV     [n],A
        JZ      FimFat

        MOV     [paMultN],A
        MOV     A,[Fat]
        MOV     [paMultM],A
        CALL    MULT
        MOV     [Fat],A
        JMP     LacFat
FimFat

        HLT

MULT
        MOV     A,0
        MOV     [resMult],A
        MOV     A,[paMultN]
        CMP     A,0
        JZ      RetMult
LacMult
        MOV     A,[resMult]
        ADD     A,[paMultM]
        MOV     [resMult],A
        MOV     A,[paMultN]
        DEC     A
        MOV     [paMultN],A
        JNZ     LacMult
RetMult
        MOV     A,[resMult]
        RET
        END
        
