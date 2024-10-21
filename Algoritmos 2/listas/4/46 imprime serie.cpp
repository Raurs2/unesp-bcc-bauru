
#include<stdio.h>

int imprimeSerie(int i, int j, int k)
{
    if (i >= j)
    {
        printf("\n");
        return 0;
    }
    printf("%d ", i);
    return imprimeSerie(i + k, j, k);
    
}
 

int main()
{
    int i = 1, j = 10, k = 2;

    imprimeSerie(i, j, k);
 
    return 0;
}