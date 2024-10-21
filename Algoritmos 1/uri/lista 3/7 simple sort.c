#include <stdio.h>
#include <math.h>

int main() {
    int x, y, z, maior, menor, meio;
    scanf("%d %d %d", &x, &y, &z);
    if (x > y && x > z)
    {
        maior = x;
        if (y > z)
        {
            meio = y;
            menor = z;
        } else {
            meio = z;
            menor = y;
        }
        
    } else if (x < y && x < z)
    {
        menor = x;
        if (y > z)
        {
            maior = y;
            meio = z;
        } else {
            maior = z;
            meio = y;
        }
    } else
    {
        meio = x;
        if (y > z)
        {
            maior = y;
            menor = z;
        } else {
            maior = z;
            menor = y;
        }
    }
    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", menor, meio, maior, x, y, z);
    return 0;
}