#include<stdio.h>
#include<string.h>

int main()
{
    int t = 1, n, i, a, b, ta, tb;
    char v[10];
    
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        ta = tb = 0;
        for ( i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            ta += a;
            tb += b;
            if (ta > tb) strcpy(v, "aldo");
            else if (tb > ta) strcpy(v, "beto");
        }
        
        printf("Teste %d\n%s\n\n", t, v);
        t++;
    } while (1);

    return 0;
}
