#include <stdio.h>
#include <stdlib.h>

/*
    Eu esqueci de avisar no primeiro mas estou usando o cpp apenas para poder iniciar uma variavel dentro do for (int i ...), não sei muito cpp,
    eu analisei os caso, primeiro se a linha é impar entao as brancas sempre estaram nas colunas impares e as pretas nas colunas pares
    outro caso se a linha é par então as pretas estarao nas colunas impares e as brancas nas colunas pares.
*/


int main()
{
    int l, c, cor;
    scanf("%d %d", &l, &c);

    if ((l % 2 != 0 && c % 2 != 0) || (l % 2 == 0 && c % 2 == 0))
    {
        cor = 1;
    } else cor = 0;

    printf("%d\n", cor);

    return 0;
}
