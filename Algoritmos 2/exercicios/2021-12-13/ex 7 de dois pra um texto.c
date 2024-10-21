#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arq1, *copia, *arq2;
    char c[101], d[101];
    int i;

    if ((arq1 = fopen("tex1.txt", "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }

    if ((arq2 = fopen("tex2.txt", "rt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    if ((copia = fopen("tex3.txt", "wt")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    while (fgets(c, 100, arq1) != NULL)
    {
        fputs(c, copia);
    }

    while (fgets(d, 100, arq2) != NULL)
    {
        fputs(d, copia);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(copia);
    
    return 0;
}
