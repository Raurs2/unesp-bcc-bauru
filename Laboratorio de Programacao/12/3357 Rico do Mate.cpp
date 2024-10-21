#include<stdio.h>

/*
    como se trata de valores ponto flutuante eu utilizei uma formula para calcular o resto, depois testei se tinha acabado o mate no primeiro
    para nao pegar uma posicao errada.
*/

int main()
{
    int n, result;
    double l, q, r;
    char nomes[11][100];

    scanf("%d %lf %lf", &n, &l, &q);

    for (int i = 0; i < n; i++)
        scanf("%s", &nomes[i]);
    
    r = l - (int)(l/q)*q;
    result = (int)(l/q) % n;
    
    if(r == 0)
    {
        r = q; 
        if(result - 1 < 0) result = n-1;
        else result -= 1;
    }

    printf("%s %.1lf\n", nomes[result], r);
    return 0;
}
