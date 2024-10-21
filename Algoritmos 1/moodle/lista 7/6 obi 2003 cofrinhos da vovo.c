#include<stdio.h>

int main()
{
    int t = 1, n, j, z, r, i;
    
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        printf("Teste %d\n", t);
        for ( i = 0; i < n; i++)
        {
            scanf("%d %d", &j, &z);
            r += j - z;
            printf("%d\n", r);
        }
        
        
        t++;
    } while (1);

    return 0;
}
