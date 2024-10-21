#include<stdio.h>
#include<string.h>

int main()
{
    int t = 1, n, i, a, b;
    char nome1[10], nome2[10], vencedor[10];
    do
    {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s %s", &nome1, &nome2);
        printf("Teste %d\n", t);
        for ( i = 0; i < n; i++)
        {
            scanf("%d %d", &a, &b);
            if ((a + b) % 2 == 0) strcpy(vencedor, nome1);
            else strcpy(vencedor, nome2);
            printf("%s\n", vencedor);
        }
        t++;
    } while (1);

    return 0;
}
