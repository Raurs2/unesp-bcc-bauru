#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *arq;
    int i, lines = 0, caracter = 0, words = 0;
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
        lines++;
        for ( i = 0; i < strlen(c); i++)
        {
            if (tolower(c[i]) >= 'a' && tolower(c[i]) <= 'z' ) caracter++;       
            
        }
    }

    rewind(arq);
    while (fscanf(arq, "%s", c) != EOF)
    {
        words++;
    }
    fclose(arq);

    printf("linhas = %d\nchar = %d\npalavras = %d\n", lines, caracter, words);

    
    
    return 0;
}
