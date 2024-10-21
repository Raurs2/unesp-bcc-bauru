#include <stdio.h>
#include <math.h>

int main() {
    int a, n, sum=0, i;

        scanf("%d %d",&a, &n);

        while (n <= 0) scanf("%d", &n);
        
        for (i = 1; i <= n;a++, i++)
        {
            sum += a;
        }
        printf("%d\n", sum);
    return 0;    
}