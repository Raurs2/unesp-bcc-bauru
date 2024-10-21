#include <stdio.h>

int main()
{
    int i, j, k, vetor[100], n;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] == vetor[i])
            {
                k = j;

                while (k < n)
                    vetor[k] = vetor[k + 1], k++;

                n--;
                j--;
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    return 0;
}