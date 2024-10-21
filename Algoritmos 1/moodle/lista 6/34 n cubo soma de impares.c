#include <stdio.h>

int cuboSoma(int n){
    int i, j, r, sum = 0, v[1000], d;
    r = n*n*n;

    for ( i = 1; sum != r; i += 2)
        for ( j = i, sum = 0, d = 0; sum < r; j += 2, d++)
        {
            sum += j;
            v[d] = j;
        }

    for ( i = 0; i < d; i++)
        printf("%d ", v[i]);
    return sum;
}

int main() {
    int n;
    
    scanf("%d", &n);
    printf("\n%d", cuboSoma(n));
    
    return 0;    
}