#include<stdio.h>

int main()
{
    int n, i = 1, n50 = 0, n10 = 0, n5 = 0, n1 = 0, v;
    do
    {
        scanf("%d", &n);
        v = n;
        n50 = n10 = n5 = n1 = 0;
        while (v != 0)
        {
            if (v / 50 != 0)
            {
                n50++;
                v -= 50;
            } else if (v / 10 != 0)
            {
                n10++;
                v -= 10;
            } else if (v / 5 != 0)
            {
                n5++;
                v -= 5;
            } else if (v / 1 != 0)
            {
                n1++;
                v -= 1;
            }
        }
        
        
        
        if (n != 0) printf("Teste %d\n%d %d %d %d\n", i, n50, n10, n5, n1);
        i++;
    } while (n != 0);
    
    
    
    return 0;
}
