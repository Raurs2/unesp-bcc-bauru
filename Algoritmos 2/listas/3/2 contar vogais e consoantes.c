#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *arq;
    int vogais = 0, consoantes = 0, i;
    char c[401], nome[30];

    //printf("Nome do arq\n");
    //gets(nome);

    if ((arq = fopen("texto.txt", "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while (fgets(c, 400, arq) != NULL)
    {
        for ( i = 0; i < strlen(c); i++)
        {
            if (tolower(c[i]) == 'a' || tolower(c[i]) == 'e' || tolower(c[i]) == 'i' || tolower(c[i]) == 'o' || tolower(c[i]) == 'u')
            {
                vogais++;
            } else if (tolower(c[i]) >= 'a' && tolower(c[i]) <= 'z')
            {
                consoantes++;
            }
        }
    }
    
    printf("vogais = %d\nconsoantes = %d", vogais, consoantes);

    fclose(arq);
    
    return 0;
}
