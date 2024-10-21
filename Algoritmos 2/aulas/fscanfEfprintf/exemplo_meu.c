#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int m[3];
    FILE *arq;

    if ((arq = fopen("texto.txt", "r+")) == NULL)
    {
        printf("Erro de abertura\n");
        exit(1);
    }
    
    while (fscanf(arq, "%d %d %d", &m[0], &m[1], &m[2]) != EOF)
    {
        fprintf(arq, "%10d %10d %10d", m[0], m[1], m[2]);
    }

    fclose(arq);
    
    return 0;
}
