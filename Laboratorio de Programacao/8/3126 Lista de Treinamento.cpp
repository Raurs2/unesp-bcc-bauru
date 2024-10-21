#include<stdio.h>


//simples se ele participou e true  entao o contador recebe mais 1

int main()
{
    int n, participou, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &participou);

        if (participou) c++;
    }
    printf("%d\n", c);
    return 0;
}
