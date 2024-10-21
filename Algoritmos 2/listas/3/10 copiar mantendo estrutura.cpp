#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arq, *copia;
    char c[101], d[101];
    int i;

    if ((arq = fopen("original.txt", "r")) == NULL)
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
        fputs(c, copia);
    }

    fclose(arq);
    fclose(copia);
    
    return 0;
}
