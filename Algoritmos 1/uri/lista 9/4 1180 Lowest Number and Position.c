#include <stdio.h>

#define max 1000

int main()
{
    int i, menor, pos;
    int a[max], n;

    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i == 0) menor = a[i];
        if (a[i] < menor) {
            pos = i;
            menor = a[i];
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, pos);
    
    
    
    return 0;
}
