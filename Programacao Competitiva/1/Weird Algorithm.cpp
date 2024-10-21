#include <stdio.h>

int main()
{
    long int N;

    scanf("%ld", &N);

    while (N != 1)
    {
        printf("%ld ", N);

        if (N % 2) N = N * 3 + 1;
        else N = N / 2;
    }

    printf("1\n");

    return 0;
}