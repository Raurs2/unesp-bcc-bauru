pos = 100
bases = [3, 5, 7, 9]

while True:
    chave = int(input('Informe a chave: '))
    aux = chave
    
    if chave < 0:
        break
    
    for base in bases:
        chave = aux
        chave_trans = ''
        
        while chave // base != 0:
            chave_trans += str(chave%base)
            chave //= base
            
        chave_trans += str(chave)
        chave_trans = chave_trans[::-1]
        indice = int(chave_trans) % pos
        
        print(f'{aux} na base({base}): {chave_trans}')
        print(f'Indice: {indice}\n')