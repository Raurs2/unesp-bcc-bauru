#include<stdio.h>

int main()
{
    int n, j, i;
    double f1 = 0, f2 = 1, fn[26], max;
    scanf("%d", &n);
    fn[0] = 0;
    fn[1] = 1;
    for (i = 2; i < 26; i++)
    {
        fn[i] = f1 + f2;
        f1 = f2;
        f2 = fn[i];
    }
    max = fn[n];
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%.0lf ", fn[j]);
        }

        printf("\n");
    }

    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf("%.0lf ", fn[j]);
        }

        printf("\n");
    }
    
    return 0;
}