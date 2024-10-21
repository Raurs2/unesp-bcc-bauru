#include <stdio.h>
#include <math.h>

int main() {
    int i, j = 7, aux = 7;
    
    for (i = 1; i <= 9; i += 2)
    {
        for (j; j >= (aux - 2); j--)
        {
            printf("I=%d J=%d\n", i, j);
        }
        aux += 2;
        j = aux;
    }
    return 0;    
}