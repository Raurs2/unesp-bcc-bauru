#include <cstdio>


/*
    testei se o jogador fez gol em toda partida, e fui incrementando um total
*/

int main()
{
    int jog, part, gols, all = 0, tot = 0;
    scanf("%d %d", &jog, &part);
    for (int i = 0; i < jog; i++)
    {
        for (int j = 0; j < part; j++)
        {
            scanf("%d", &gols);
            if (gols) all++;
        }
        if (all == part) tot++;
        all = 0;
    }
    printf("%d\n", tot);
    
    return 0;
}
