#include <stdio.h>
#include <stdlib.h>

/*
    Fui lendo instrução por instrucao e fazendo, coloquei a linha de '-' e de ' ' pois se repetiam, pensei em fazer tudo em funcao também,
    exemplo uma funcao que recebia por parametro onde inicia e acabava o for e oque escreveria, assim consumiria menos linhas de codigo mas como
    ja havia começado a escrever seguindo linha por linha decidi continuar assim para sobrar mais tempo para os proximos exercicios.

*/

void dashes(){
    for (int i = 1; i <= 39; i++)
    {
        printf("-");
    }
}

void white_space(){
    printf("|\n|");
    for (int i = 2; i <= 38; i++)
    {
        printf(" ");
    }
    printf("|\n|");
}

int main()
{
    dashes();

    printf("\n|x = 35");
    for ( int i = 8; i <= 38; i++)
    {
        printf(" ");
    }

    white_space();

    for (int i = 2; i <= 16; i++)
    {
        printf(" ");
    }
    printf("x = 35");
    for (int i = 23; i <= 38; i++)
    {
        printf(" ");
    }

    white_space();

    for (int i = 2; i <= 32; i++)
    {
        printf(" ");
    }
    printf("x = 35|\n");

    dashes();

    printf("\n");
    return 0;
}
