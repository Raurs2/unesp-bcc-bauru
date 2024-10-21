#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *arq;
    int d;
    char a[100];
    if ((arq = fopen("binarios.txt", "w")) == NULL)
    {
        printf("Erro de abertura");
        exit(1);
    }
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &d);
        itoa(d, a, 2);
        fputs(a, arq);
        fputs("\n", arq);
    }
    fclose(arq);
    
    return 0;
}
