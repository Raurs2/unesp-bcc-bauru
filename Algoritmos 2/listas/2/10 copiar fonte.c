#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//CHAVE, INFORMAÇÃO e DATA
typedef struct 
{
    int key;
    char info[200];
    int d, m, a;
} fonte;

int main()
{
    int op, n;
    FILE *arq, *copia;
    fonte f;

    if ((arq = fopen("FONTE.dat", "rb")) == NULL)
    {
        printf("Erro de abertura 1");
        exit(1);
    }
    
    if ((copia = fopen("FONTENOVA.dat", "wb")) == NULL)
    {
        printf("Erro de abertura 2");
        exit(1);
    }
    
    while (fread(&f, sizeof(n), 1, arq) == 1)
    {
            fwrite(&f, sizeof(n), 1, copia);
    }
    printf("copiado\n");
    fclose(arq);
    fclose(copia);
    
    return 0;
}
