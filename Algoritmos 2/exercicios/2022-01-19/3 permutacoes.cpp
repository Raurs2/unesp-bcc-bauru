#include<stdio.h>

int fat(int n)
{
    if (n == 0)
    {
        return 1;
    } else
    {
        return n * fat(n-1);
    }
}

void permu(int n, char symbols[8])
{
    if (symbols[n] == 'A')
    {
        printf("\n");
    } else
    {
        printf("%c", symbols[n]);
        permu(n-1, symbols);
    }
    
}

int main()
{
    int n;
    printf("Permutacao de quantos simbolos? Max 8\n");
    scanf("%d", &n);
    printf("%d possiveis combinacoes\n", fat(n));
    
    char symbols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    return 0;
}
