#include <stdio.h>

#define max 100

int main()
{
    int i, vetor[max], aux;
    
    /* ... */
    for (i = 7; i >= 3; i--) {
    aux = vetor[i];
    vetor[i] = vetor[7-i];
    vetor[7-i] = aux;
    }
    vetor[2] = vetor[0];
    vetor[vetor[1]] = vetor[vetor[1]];
    /* ... */
    for ( i = 0; i < max; i++)
    {
        printf("%d ", vetor[i]);
    }
    
       
    return 0;
}
