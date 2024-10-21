#include <stdio.h>
#include <math.h>
int main() {
    int cod, c1 = 0, c2 = 0, c3 = 0, c4 = 0, vn = 0, vb = 0, i = 1, tot, vence;
    do
    {
        printf("1, 2, 3, 4 = candidatos\n5 = nulo 6 = em branco 7 = sair\n");
        scanf("%d", &cod);
        switch (cod)
        {
        case 1:
            c1 += 1;
            break;
        case 2:
            c2 += 1;
            break;
        case 3:
            c3 += 1;
            break;
        case 4:
            c4 += 1;
            break;
        case 5:
            vn += 1;
            break;
        case 6:
            vb += 1;
            break;
        case 7:
            i = 0;
            break;
        }
    } while (i);
    if (c1 > c2 && c1 > c3 && c1 > c4)
    {
        vence = 1;
    } else if (c2 > c1 && c2 > c3 && c2 > c4)
    {
        vence = 2;
    } else if (c3 > c2 && c3 > c1 && c3 > c4)
    {
        vence = 3;
    } else if (c4 > c2 && c4 > c3 && c4 > c1)
    {
        vence = 4;
    }
    
    tot = c1 + c2 + c3 + c4 + vn + vb;
    printf("candidato 1 = %d\ncandidato 2 = %d\ncandidato 3 = %d\ncandidato 4 = %d\nVotos nulos = %d\nVotos brancos = %d\nbranco e nulo / total = %d%%\nVencedor = %d", c1, c2, c3, c4, vn, vb, (vb + vn)*100/tot, vence);
    return 0;
}