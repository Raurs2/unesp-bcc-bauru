#include <stdio.h>

int main()
{
    int test;
    float n1, n2, n3;
    
    scanf("%d", &test);

    do
    {
        scanf("%f %f %f", &n1, &n2, &n3);
        printf("%.1f\n", (n1*2 + n2*3 + n3*5) / 10);
        test--;
    } while (test > 0);
    
    return 0;
}
