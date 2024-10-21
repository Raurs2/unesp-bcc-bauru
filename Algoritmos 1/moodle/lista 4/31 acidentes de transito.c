#include <stdio.h>
#include <math.h>
int main() {
    int cod, numVeic, numAcident, i, menor;
    int v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    float avrVeiculos, avrAcidentes = 0;
    
    for (i = 1; i <= 5; i++)
    {
        scanf("%d %d %d", &cod, &numVeic, &numAcident);
        switch (cod)
        {
        case 1:
            v1 = numVeic;
            a1 = numAcident;
            break;
        case 2:
            v2 = numVeic;
            a2 = numAcident;
            break;
        case 3:
            v3 = numVeic;
            a3 = numAcident;
            break;
        case 4:
            v4 = numVeic;
            a4 = numAcident;
            break;
        case 5:
            v5 = numVeic;
            a5 = numAcident;
            break;
        }
    }
    avrVeiculos = (v1 + v2 + v3 + v4 + v5)/5;
    
    if (a1 > a2 && a1 > a3 && a1 > a4 && a1 > a5)
    {
        cod = 1;
    } else if (a2 > a1 && a2 > a3 && a2 > a4 && a2 > a5)
    {
        cod = 2;
    } else if (a3 > a2 && a3 > a1 && a3 > a4 && a3 > a5)
    {
        cod = 3;
    } else if (a4 > a2 && a4 > a3 && a4 > a1 && a4 > a5)
    {
        cod = 4;
    } else if (a5 > a2 && a5 > a3 && a5 > a4 && a5 > a1)
    {
        cod = 5;
    }

    if (a1 < a2 && a1 < a3 && a1 < a4 && a1 < a5)
    {
        menor = 1;
    } else if (a2 < a1 && a2 < a3 && a2 < a4 && a2 < a5)
    {
        menor = 2;
    } else if (a3 < a2 && a3 < a1 && a3 < a4 && a3 < a5)
    {
        menor = 3;
    } else if (a4 < a2 && a4 < a3 && a4 < a1 && a4 < a5)
    {
        menor = 4;
    } else if (a5 < a2 && a5 < a3 && a5 < a4 && a5 < a1)
    {
        menor = 5;
    }

    if (v1 < 2000)
    {
        avrAcidentes += a1;
    }  if (v2 < 2000)
    {
        avrAcidentes += a2;
    } if (v3 < 2000)
    {
        avrAcidentes += a3;
    } if (v4 < 2000)
    {
        avrAcidentes += a4;
    } if (v5 < 2000)
    {
        avrAcidentes += a5;
    }
    
    avrAcidentes /= 5;
    
    printf("Maior: %d Menor: %d\nMedia veiculos: %.2f\nMedia Acidentes: %.2f", cod, menor, avrVeiculos, avrAcidentes);
    return 0;
}