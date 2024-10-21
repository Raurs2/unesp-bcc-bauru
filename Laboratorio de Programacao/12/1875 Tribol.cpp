#include<stdio.h>

/*
    fiz uma pontuacao para cada dependendo da pontuacao printei o resultado da partida
*/

int main()
{
    int n, gols, gpoints, rpoints, bpoints;
    char marcou, sofreu;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &gols);

        rpoints = gpoints = bpoints = 0;
        for (int j = 0; j < gols; j++)
        {
            scanf("%c %c\n", &marcou, &sofreu);

            if (marcou == 'R')
            {
                if (sofreu == 'G') rpoints += 2;
                else rpoints++;
            }
            else if (marcou == 'G')
            {
                if (sofreu == 'B') gpoints += 2;
                else gpoints++;
            } else
            {
                if (sofreu == 'R') bpoints += 2;
                else bpoints++;
            }

        }

        if (gpoints == rpoints && gpoints == bpoints)
            printf("trempate\n");
        else if ((gpoints == rpoints && gpoints > bpoints) || (gpoints == bpoints && gpoints > rpoints) || (bpoints == rpoints && bpoints > gpoints))
            printf("empate\n");
        else
        {
            if (bpoints > gpoints && bpoints > rpoints)
                printf("blue\n");
            else if (gpoints > bpoints && gpoints > rpoints)
                printf("green\n");
            else
                printf("red\n"); 
        }

    }

    return 0;
}
