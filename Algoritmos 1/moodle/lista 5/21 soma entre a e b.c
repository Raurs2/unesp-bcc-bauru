#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, sum = 0;

    scanf("%d %d", &a, &b);

    for (a; a <= b; a++)
    {
            sum += a;
        
    }

    printf("%d  ", sum);
    return 0;
}
