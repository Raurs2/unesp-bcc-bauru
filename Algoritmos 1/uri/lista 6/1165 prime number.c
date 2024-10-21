#include <stdio.h>

int main()
{
    int test, x, i, sum;
    scanf("%d", &test);

    do
    {   
        sum = 0;
        scanf("%d", &x);

        for (i = 1; i <= x; i++)
        {
            if (x % i == 0)
            {
                sum++;
            }
            
        }

        if (sum == 2) {
            printf("%d eh primo\n", x);
        } else{
            printf("%d nao eh primo\n", x);
        } 
        
        test--;
    } while (test > 0);
    
    return 0;
}
