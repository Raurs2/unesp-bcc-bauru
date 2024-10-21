direita = true
x = 1
porta = false
enquanto nao porta:
    se direita:
        dar x passo a direita
        verificar a posicao do muro
    se nao direita:
        dar x passo a esquerda
        verificar a posicao do muro
    x++
    direita = nao direita
entrar na porta
