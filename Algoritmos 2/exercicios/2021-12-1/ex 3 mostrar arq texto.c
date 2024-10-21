#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *arq;
    int vogais = 0, consoantes = 0;
    char c, nome[30];

    printf("Nome do arq\n");
    gets(nome);

    if ((arq = fopen(nome, "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while ((c = getc(arq)) != EOF)
    {
        if (c != EOF) printf("%c", c);
    }

    fclose(arq);
    
    return 0;
}
