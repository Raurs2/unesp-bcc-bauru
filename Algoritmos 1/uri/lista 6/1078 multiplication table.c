#include <stdio.h>

int main()
{
    int test, i;
    
    scanf("%d", &test);

    for (i = 1; i <= 10; i++)
    {
       printf("%d x %d = %d\n", i, test, i*test);
    }
    return 0;
}
