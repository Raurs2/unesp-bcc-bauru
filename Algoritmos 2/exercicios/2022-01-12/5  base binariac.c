#include <stdio.h>

int binarioR(int n)
{
    if (n == 0)
        return 0;
    return ((n % 2) + 10 * binarioR(n/2));
    
}

int main () {
    printf("%d\n", binarioR(6));
    return 0;
}