#include<stdio.h>

int main()
{
    int n, p, x, y, c = 0, i;
    
        scanf("%d %d", &n, &p);
        for ( i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &y);
            if ((x + y) >= p) c++;
        }
        
        printf("%d\n\n", c);

    return 0;
}
