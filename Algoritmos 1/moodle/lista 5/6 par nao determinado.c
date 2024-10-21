#include <stdio.h>
#include <math.h>
int main() {
    int a, b, sum = 0;
    do
    {
        scanf("%d %d", &a, &b);
        if (a >= b)
        {
            return 0;
        }
        for (a; a <= b; a++)
        {
            sum += a;
        }
        printf("Soma: %d\n", sum);
        sum = 0;
    } while (1);
    return 0;
}