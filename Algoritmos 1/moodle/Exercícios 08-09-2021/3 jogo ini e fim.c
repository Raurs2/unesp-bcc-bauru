#include <stdio.h>
#include <math.h>
int hora(int h1, int h2, int m1, int m2, int *hf, int *mf) {
    
    if (h1 == h2 && m1 >= m2)
    {
        *hf = 24;
    } else if ((h1 > 12 && h2 <= 12) || (h1 > h2))
    {
        *hf = (24 - h1) + h2;
    }
    else if ((h1 > 12 && h2 > 12) || (h1 <= 12 && h2 > 12) || (h1 <= 12 && h2 <= 12))
    {
        *hf = h2 - h1;
    }

    if (m1 <= m2)
    {
        *mf = m2 - m1;
    } else {
        *mf = ((*hf - (*hf-1)) * 60) - (m1 - m2);
        *hf = *hf - 1;
    }
}
int main() {
    int h1, h2, m1, m2, hf, mf;

    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

    hora(h1, h2, m1, m2, &hf, &mf);
    
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hf, mf);
    return 0;
}