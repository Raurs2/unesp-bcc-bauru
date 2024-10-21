#include <stdio.h>
#include <math.h>

int main()
{
    int i;

    for (i = 3500; i < 7000; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d  ", i);
        }   
    }
    return 0;
}
