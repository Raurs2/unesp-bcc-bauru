#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arq, *copia;
    char c[101], d[101], name[30] = "ajuda.txt";
    int i;

    if ((arq = fopen(name, "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    if ((copia = fopen("copia.txt", "w")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while (fgets(c, 100, arq) != NULL)
    {
        for ( i = 0; i < strlen(c); i++)
            c[i] += 4;
        fputs(c, copia);
    }

    fclose(arq);
    fclose(copia);
    
    return 0;
}
