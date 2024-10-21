#include<stdio.h>
#include<string.h>

/*
    vejo se na string tem RA no inicio e se o tamanho dela é 20
    se sim é um ra valido entao imprimo a parte numerica como senha
    senao eu imprimo o invalid data
*/

int main()
{
    int istam, isra, iszero;
    char s[101];
    int n;
    unsigned long long int a;

    scanf("%d\n", &n);
    
    for (int i = 0; i < n; i++)
    {
        fgets(s, sizeof(s), stdin);
        sscanf(s, "RA%llu", &a);

        istam = strlen(s) == 21;
        isra = s[0] == 'R' && s[1] == 'A';
        iszero = a == 0;

        if (istam && isra && !iszero)
        {
            printf("%llu\n", a);
        } else
        {
            printf("INVALID DATA\n");
        }
    }

    return 0;
}
