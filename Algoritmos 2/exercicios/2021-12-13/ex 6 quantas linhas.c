#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *arq;
    char c[401], nome[30];
    int i = 0;

    //printf("Nome do arq\n");
    //gets(nome);

    if ((arq = fopen("texto.txt", "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while (fgets(c, 400, arq) != NULL)
    {
        i++;
    }
    printf("%d", i);
    fclose(arq);
    
    return 0;
}
