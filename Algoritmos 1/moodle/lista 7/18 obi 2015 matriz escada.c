#include<stdio.h>
#include<math.h>

int main()
{
    int m, n, e, cont, index = -1, eh = 1, priEsq, j, i;
    
    scanf("%d %d", &n, &m);

    for ( i = 0; i < n; i++, priEsq = 1, cont = 0)
    {
        for ( j = 0; j < m; j++) {
            scanf("%d", &n);

            if (e == 0 && priEsq) cont++;
            else priEsq = 0;
        }
        if (cont <= index && cont < m) eh = 0;
        
        index = cont;
    }

    if (eh) printf("S");
    else printf("N");

    return 0;
}
