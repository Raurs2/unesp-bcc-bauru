#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arquivo;
    char c[200];
    int i;
    
    if ((arquivo = fopen("copia.txt", "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    while (fgets(c, 100, arquivo) != NULL)
    {
        for ( i = 0; i < strlen(c); i++)
            printf("%c", c[i] - 4);
    }

    fclose(arquivo);
    
    return 0;
}
