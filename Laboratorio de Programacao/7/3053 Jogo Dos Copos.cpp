#include <stdio.h>
#include <ctype.h>
#include <string.h>

void zerar(int copos[3])
{
    for (int i = 0; i < 3; i++)
        copos[i] = 0;
}

void iniciar(int copos[3], char pos)
{
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
}

void movimentos(int copos[3], int n)
{
    int mov, aux;
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
}

int main()
{
    int n, copos[3];
    scanf("%d", &n);

    zerar(copos);

    char pos, posend;
    scanf("%c", &pos);

    iniciar(copos, pos);

    movimentos(copos, n);

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
    
    printf("%c", posend);
    return 0;
}
