#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    li as duas strings e depois usei a funcao strcmp para comparar as strings dependendo do resultado da comparacao
    fiz um print pra ele, caso primeiro é menor ou caso sao iguais ou caso primeiro é maior
*/


int main()
{
    char a[21], b[21];
    scanf("%s", a);
    scanf("%s", b);

    int c = strcmp(a, b);
    if (c == -1)
    {
        printf("%s\n%s\n", a, b);
    } else if (c == 0)
    {
        printf("%s\n%s\n", a, b);
    } else if (c == 1)
    {
        printf("%s\n%s\n", b, a);
    }
    
    return 0;
}
