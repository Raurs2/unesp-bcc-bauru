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
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
        {
            vogais++;
        } else if (tolower(c) >= 'a' && tolower(c) <= 'z')
        {
            consoantes++;
        }
    }
    
    printf("vogais = %d\nconsoantes = %d", vogais, consoantes);

    fclose(arq);
    
    return 0;
}
