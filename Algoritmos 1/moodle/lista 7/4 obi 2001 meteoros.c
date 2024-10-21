#include<stdio.h>

int main()
{
    int x1, x2, y1, y2, n, x, y, nf, i, j, t = 1;
    do
    {
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) break;

        scanf("%d", &n);
        nf = 0;
        for ( i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &y);
            if(x >= x1 && x <= x2 && y <= y1 && y >= y2) nf++;
        }
        
        printf("Teste %d\n%d\n\n", t, nf);
        t++;
    } while (1);
    
    
    
    return 0;
}
