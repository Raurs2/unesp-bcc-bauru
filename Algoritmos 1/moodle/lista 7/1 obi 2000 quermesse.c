#include<stdio.h>

int main()
{
    int n, i = 1, j, p, r;
    do
    {
        scanf("%d", &n);

        for (j = 1; j <= n; j++)
        {
            scanf("%d", &p);
            if (p == j) r = p;
        }
        if (n != 0) printf("Teste %d\n%d\n", i, r);
        i++;
    } while (n != 0);
    
    
    
    return 0;
}
