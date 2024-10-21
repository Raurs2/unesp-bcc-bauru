#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arq, *copia;
    char c[101], d[101], name[30];
    int i;
    scanf("%s", name);
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
            if (tolower(c[i]) == 'a' || tolower(c[i]) == 'e' || tolower(c[i]) == 'i' || tolower(c[i]) == 'o' || tolower(c[i]) == 'u')
                c[i] = '*';
        fputs(c, copia);
    }

    fclose(arq);
    fclose(copia);
    
    return 0;
}
