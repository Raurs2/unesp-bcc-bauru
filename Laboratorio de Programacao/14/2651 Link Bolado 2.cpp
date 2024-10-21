#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 100000

int main ()
{
    int N, C = 0, i, j, k;
    char Link[max], Nome[] = {"zelda"}, Compara[6];
    fgets(Link, sizeof(Link), stdin);
    N = strlen(Link);
    for(i = 0; (i < N - 5) && (C != 1); i++)
    {
        k = 0;
        for(j = i; j < i + 5; j++)
        {
            Compara[k] = tolower(Link[j]);
            k++;
        }
        Compara[5] = '\0';
        if(strcmp(Nome, Compara) == 0)
        {
            C = 1;
        }
    }
    if(C == 1)
    {
        printf("Link Bolado\n");
    }
    else
    {
        printf("Link Tranquilo\n");
    }
    return 0;
}