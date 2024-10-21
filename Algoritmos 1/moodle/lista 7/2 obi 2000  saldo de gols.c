#include<stdio.h>

int main()
{
    int t = 1, n, x, y, first, last, gols, i, sum, best_sum, from, to;
    
    do
    {
        scanf("%d", &n);
        if (n == 0) break;

        sum = 0;
        best_sum = -1;
        for ( i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &y);
            sum += x - y;

            if (sum > best_sum)
            {
                from = i;
            }
            
        }
        
        if (gols <= 0) printf("Teste %d\nnenhum\n\n", t);
        printf("Teste %d\n%d %d\n\n", t, first, last);
        t++;
    } while (1);

    return 0;
}
