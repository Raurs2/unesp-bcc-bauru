#include <stdio.h>

int main()
{
    int n, k, a[101], menor = 9999;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if (k / a[i] < menor && k % a[i] == 0)
        {
            menor = k / a[i];
        }
    }

    if (menor < 9999)
    {
        printf("%d\n", menor);
    } else
    {
        printf("NO SOLUTION\n");
    }
    
    return 0;
}