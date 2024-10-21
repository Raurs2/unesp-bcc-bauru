#include<stdio.h>
#include <math.h>

/*
    crie uma lista dos primos pelo algoritmo do crivo, depois escaniei o numero de casos e adicionei
    um em cada caso, depois testei se o caso é divisivel por 7, impar e se ele + 2 é primo
    se sim é um ataque do bandido
*/

void crivo(int primos[])
{
    int raiz = sqrt(10001);

    for(int i = 2; i <= 10001; i++)
        primos[i] = i;

    for(int i = 2; i <= raiz; i++)
        if(primos[i] == i)
            for(int j = i+i; j <= 10001; j += i)
                primos[j] = 0;
}

int main()
{
    int n, n1, primos[10001] = {};
    
    crivo(primos);

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &n1);
        n1 += 1;

        if(!(n1%7) && n1%2 && primos[n1+2]) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
