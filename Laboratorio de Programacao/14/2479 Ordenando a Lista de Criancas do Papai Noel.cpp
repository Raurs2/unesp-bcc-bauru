#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/*
    peguei a lista e armazenei o as criancas comportadas, para ter as nao comportadas subtrai as comportadas do total, usei o qsort para organizar a lista
    e imprimi a lista ordenada e o numero de criancas comportadas e nao comportadas
*/

int sortstring(const void *v1, const void *v2)
{
    return (strcmp((char*) v1, (char*) v2));
}

int main()
{
    int n, comportadas = 0, tam;
    char c, s[101][21];
    
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%c \n", &c);
        fgets(s[i], sizeof(s[i]), stdin);
        if (c == '+') comportadas++; 
    }

    qsort(s, n, sizeof(s[0]), sortstring);
    
    for (int i = 0; i < n; i++)
    {
        printf("%s", s[i]);

        tam = strlen(s[i]);
        if(s[i][tam - 1] != '\n') printf("\n");       
    }
    printf("Se comportaram: %d | Nao se comportaram: %d\n", comportadas, n - comportadas);
    return 0;
}
