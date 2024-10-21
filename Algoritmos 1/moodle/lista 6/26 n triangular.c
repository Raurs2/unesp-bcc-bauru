#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n, i = 1;
    scanf("%d", &n);
    do
    {
        

        if (i*(1+i)*(2+i) == n)
            break;
        i++;

    } while (1);
    printf("%d %d %d = %d", i, i+1, i+2, n);
    return 0;    
}