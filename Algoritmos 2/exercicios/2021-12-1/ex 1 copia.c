#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int op;
    FILE *arq, *copia;
    char c;

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
    
    while (!feof(arq))
    {
        c = getc(arq);
        if (!feof(arq))
        {
            putc(toupper(c), copia);
        }
        
    }

    fclose(arq);
    fclose(copia);
    
    return 0;
}
