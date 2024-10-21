#include <stdio.h>

int main()
{
    int test, n, i;
    
    scanf("%d", &test);

    for (i = 1; i <= test; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d^2 = %d\n", i, i*i);
        }
        
    }
    
    return 0;
}
