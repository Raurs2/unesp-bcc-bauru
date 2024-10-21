#Raul Alexandre Gonzalez Augusto RA 211023698

str = input().split() #divide a string digitada pelos ' ' em uma lista de palavras

for word in str: #for percorrendo elementos da str
    print(word[::-1], end=" ") #imprime todo o elemento apartir do final depois adiciona um ' '