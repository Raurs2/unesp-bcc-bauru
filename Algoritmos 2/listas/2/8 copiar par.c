#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int op, n;
    FILE *arq, *copia;
    

    if ((arq = fopen("numeros.bin", "rb")) == NULL)
    {
        printf("Erro de abertura 1");
        exit(1);
    }
    
    if ((copia = fopen("pares.bin", "wb")) == NULL)
    {
        printf("Erro de abertura 2");
        exit(1);
    }
    
    while (fread(&n, sizeof(n), 1, arq) == 1)
    {
        if (n % 2 == 0)
        {
            printf("%d\n", n);
            fwrite(&n, sizeof(n), 1, copia);
        }
    }

    fclose(arq);
    fclose(copia);
    
    return 0;
}
