#include <stdio.h>
#include <math.h>
int main() {
    int i, n, o;
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        o = n + 11;
    } else {
        o = n + 10;
    }
    
    for ( i = n; i <= o; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d\n", i);
        }
        
    }
    return 0;
}