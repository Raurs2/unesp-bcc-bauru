#include <stdio.h>
#include <string.h>
/*
    criei um vetor com 3 posicao com 0 se n tem copo e 1 se tem copo, depois fiz um aux pra cada movimentacao mudando
    o valor das posicoes conforme o numero do movimento, por fim mostrei a posicao final do copo 
*/
int main()
{
    int n, copos[3], mov, aux;
    scanf("%d", &n);
    
    getc(stdin);
    for (int i = 0; i < 3; i++)
        copos[i] = 0;

    char pos, posend;
    scanf("%c", &pos);
    
    if (pos == 'A')
    {
        copos[0] = 1;
    } else if (pos == 'B')
    {
        copos[1] = 1;
    } else if (pos == 'C')
    {
        copos[2] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mov);
        if (mov == 1)
        {
            aux = copos[0];
            copos[0] = copos[1];
            copos[1] = aux;
        } else if (mov == 2)
        {
            aux = copos[1];
            copos[1] = copos[2];
            copos[2] = aux;
        } else if (mov == 3)
        {
            aux = copos[0];
            copos[0] = copos[2];
            copos[2] = aux;
        }
    }

    if (copos[0] == 1)
    {
        posend = 'A';
    } else if (copos[1] == 1)
    {
        posend = 'B';
    } else if (copos[2] == 1)
    {
        posend = 'C';
    }
    
    printf("%c\n", posend);
    return 0;
}
