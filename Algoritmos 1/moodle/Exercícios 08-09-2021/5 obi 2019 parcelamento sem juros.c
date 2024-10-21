#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int v, p, i, r;
    do
    {
        scanf("%d", &v);
        if (v == 0) break;
        scanf("%d", &p);
        r = v % p;
        v /= p;
        for ( i = 1; i <= p; i++)
        {
            if (r != 0) {
                printf("%d\n", v + 1);
                r--;
            }
            else printf("%d\n", v);
        }
        
    } while (1);
    
    return 0;
}
