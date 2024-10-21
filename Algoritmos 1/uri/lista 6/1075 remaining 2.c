#include <stdio.h>

int main()
{
    int test, i;
    
    scanf("%d", &test);

    for (i = 1; i <= 10000; i++)
    {
        if (i % test == 2)
        {
            printf("%d\n", i);
        }   
    }
    return 0;
}
