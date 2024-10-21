#include <stdio.h>

int main()
{
    int test, x, i, sum;
    scanf("%d", &test);

    do
    {   
        sum = 0;
        scanf("%d", &x);

        for (i = 1; i < x; i++)
        {
            if (x % i == 0)
            {
                sum += i;
            }
            
        }

        if (sum == x) printf("%d eh perfeito\n", x);
        else printf("%d nao eh perfeito\n", x);
        
        test--;
    } while (test > 0);
    
    return 0;
}
