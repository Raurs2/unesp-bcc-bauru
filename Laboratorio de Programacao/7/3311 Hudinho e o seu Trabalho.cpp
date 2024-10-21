#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define max 1000
// provavelmente tem um jeito mais otimizado mas eu fiz da seguinte maneira
// depois de gravar os nomes criei uma funcao que percorre eles e se o nome bate coom a letra que eu
// usei de parametro ele adiciona o nome nos ordenados. porem esse metodo significa que o programa
// vai ter que roda pela lista de nomes para cada letra do alfabeto depois printei a lista ordenada
int ordena(char nomes[max][1000], char letra, char ordenados[max][1000], int pos, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (nomes[i][0] == letra)
        {
            strcpy(ordenados[pos], nomes[i]);
            pos++;
        }   
    } 
    return pos;
}

int main()
{
    int n, pos = 0;
    scanf("%d", &n);

    char nomes[max][1000];
    char ordenados[max][1000];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", nomes[i]);
    }
    
    pos = ordena(nomes, 'A', ordenados, pos, n);
    pos = ordena(nomes, 'B', ordenados, pos, n);
    pos = ordena(nomes, 'C', ordenados, pos, n);
    pos = ordena(nomes, 'D', ordenados, pos, n);
    pos = ordena(nomes, 'E', ordenados, pos, n);
    pos = ordena(nomes, 'F', ordenados, pos, n);
    pos = ordena(nomes, 'G', ordenados, pos, n);
    pos = ordena(nomes, 'H', ordenados, pos, n);
    pos = ordena(nomes, 'I', ordenados, pos, n);
    pos = ordena(nomes, 'J', ordenados, pos, n);
    pos = ordena(nomes, 'K', ordenados, pos, n);
    pos = ordena(nomes, 'L', ordenados, pos, n);
    pos = ordena(nomes, 'M', ordenados, pos, n);
    pos = ordena(nomes, 'N', ordenados, pos, n);
    pos = ordena(nomes, 'O', ordenados, pos, n);
    pos = ordena(nomes, 'P', ordenados, pos, n);
    pos = ordena(nomes, 'Q', ordenados, pos, n);
    pos = ordena(nomes, 'R', ordenados, pos, n);
    pos = ordena(nomes, 'S', ordenados, pos, n);
    pos = ordena(nomes, 'T', ordenados, pos, n);
    pos = ordena(nomes, 'U', ordenados, pos, n);
    pos = ordena(nomes, 'V', ordenados, pos, n);
    pos = ordena(nomes, 'W', ordenados, pos, n);
    pos = ordena(nomes, 'X', ordenados, pos, n);
    pos = ordena(nomes, 'Y', ordenados, pos, n);
    pos = ordena(nomes, 'Z', ordenados, pos, n);


    for (int i = 0; i < n; i++)
    {
        printf("%s\n", ordenados[i]);
    }

    /*for (int i = 0; i < n; i++)
    {
        printf("%s\n", nomes[i]);
    }*/
    return 0;
}
