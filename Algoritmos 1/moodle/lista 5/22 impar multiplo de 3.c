#include <stdio.h>
#include <math.h>

int main()
{
    int sum = 0, i;

    for (i = 1; i <= 700; i++)
    {
        if (i % 2 != 0 && i % 3 == 0)
        {
            sum += i;
        }  
    }

    printf("%d  ", sum);
    return 0;
}
