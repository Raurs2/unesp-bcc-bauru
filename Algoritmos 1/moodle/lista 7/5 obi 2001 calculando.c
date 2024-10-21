#include<stdio.h>

int main()
{
    int t = 1, n, r, v, i;
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        
        r = 0;
        for ( i = 0; i < n; i++)
        {
            scanf("%d", &v);
            r += v; 
        }

        printf("Teste %d\n%d\n\n", t, r);
        t++;
    } while (1);

    return 0;
}
