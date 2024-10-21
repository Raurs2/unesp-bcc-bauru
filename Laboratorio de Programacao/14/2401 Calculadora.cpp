#include<stdio.h>
#include<stdlib.h>

/*
    depois de pegar a quantidade de numeros, fiz um for para pegar as contas e ir armazenando num resultado.
*/

int main()
{
    int n, n1;
    double r = 1;
    char op;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &n1, &op);
        if (op == '*') r *= n1;
        else r /= n1;
    }

    printf("%.0f\n", r);

    return 0;
}
