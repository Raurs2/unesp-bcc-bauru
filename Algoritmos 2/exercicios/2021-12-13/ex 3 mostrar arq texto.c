#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    char c[401], nome[30];

    //printf("Nome do arq\n");
    //gets(nome);

    if ((arq = fopen("texto.txt", "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while (fgets(c, 400, arq) != NULL)
    {
        printf("%s", c);
    }

    fclose(arq);
    
    return 0;
}
