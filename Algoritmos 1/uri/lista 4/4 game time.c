#include <stdio.h>
#include <math.h>

int main() {
    int h1, h2, m1, m2, hf, mf;

    scanf("%d %d", &h1, &h2);
    //scanf("%d %d %d %d", &h1, &h2, &m1, &m2);
    if (h1 == h2)
    {
        hf = 24;
    } else if ((h1 > 12 && h2 <= 12) || (h1 > h2))
    {
        hf = (24 - h1) + h2;
    }
    else if ((h1 > 12 && h2 > 12) || (h1 <= 12 && h2 > 12) || (h1 <= 12 && h2 <= 12))
    {
        hf = h2 - h1;
    }
    printf("O JOGO DUROU %d HORA(S)\n", hf);
    //printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hf, mf);
    return 0;
}