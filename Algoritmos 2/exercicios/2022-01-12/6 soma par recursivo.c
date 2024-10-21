#include <stdio.h>


int somaR (int n, int sum) {
    if (sum > n)
    {
        printf(" = %d", sum);
        return 0;
    } else
    {
        printf("%d", sum);
        printf(" + ");
        return sum + somaR(n, sum+2);
    }
}

int main () {
    somaR(9, 0);
    return 0;
}