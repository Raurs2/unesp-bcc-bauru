#include <stdio.h>
#include <math.h>

#define max 100

int main()
{
    double vet[max], n = 10;
    int  i, j;

    //A
    for ( i = 0; i < max; i++)
    {
        vet[i] = 15;
        printf("%.0lf ", vet[i]);
    }
    printf("\n\n");

    //B
    for ( i = 0; i < max; i++)
    {
        vet[i] = n;
        n += 10;
        printf("%.0lf ", vet[i]);
    }
    printf("\n\n");

    //C
    for ( i = 0; i < max; i++)
    {
        
        if (sqrt(i) == (int)sqrt(i)) vet[i] = 1;
        else vet[i] = 0;
        
        printf("%.0lf ", vet[i]);
    }
       
    return 0;
}
