#include <stdio.h>

int main()
{
    int n1, n2, sum = 0, aux;
    
    scanf("%d %d", &n1, &n2);

    if (n1 > n2)
    {
        aux = n2;
        n2 = n1;
        n1 = aux;
    }

    for (n1 += 1; n1 < n2; n1++)
    {
        if (n1 % 2 != 0)
        {
            sum += n1;
        }    
    }
    
    printf("%d\n", sum);
    
    return 0;
}
