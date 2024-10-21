#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arq, *copia;
    char c[101];

    if ((arq = fopen("texto.txt", "r")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    
    if ((copia = fopen("vogais.txt", "w")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }

    while (fgets(c, 400, arq) != NULL)
    {
        printf("%s", c);
    }
    rewind(arq);
    int words = 0;
    while (fscanf(arq, "%s", c) != EOF)
    {
        words++;
        if (tolower(c[0]) == 'a' || tolower(c[0]) == 'e' || tolower(c[0]) == 'i' || tolower(c[0]) == 'o' || tolower(c[0]) == 'u')
        {
            fprintf(copia, "%s\n", c);
        }
    }

    fclose(arq);
    fclose(copia);
    
    return 0;
}
