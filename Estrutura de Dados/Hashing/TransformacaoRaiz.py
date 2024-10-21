while True:
    chave = int(input('Informe a chave: '))
    
    if chave < 0:
        break
    
    base = int(input('Informe a base: '))
    pos = int(input('Informe a qtd de posições: '))
    
    chave_trans = ''
    while chave // base != 0:
        chave_trans += str(chave%base)
        chave //= base
    chave_trans += str(chave)
    
    chave_trans = chave_trans[::-1]
    indice = int(chave_trans) % pos
    
    print(f'Chave: {chave_trans}')
    print(f'Indice: {indice}')
        
    
    