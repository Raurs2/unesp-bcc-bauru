#include <stdio.h>
#include <math.h>
int main() {
    int dia, mes;
    scanf("%d %d", &dia, &mes);
    switch (mes)
    {
    case 1:
        if (dia <= 20)
        {
            printf("Capricornio\n");
        } else {
            printf("Aquario\n");
        }
        break;
    case 2:
        if (dia <= 19)
        {
            printf("Aquario\n");
        } else {
            printf("Peixes\n");
        }
        break;
    case 3:
        if (dia <= 20)
        {
            printf("Peixes\n");
        } else {
            printf("Aries\n");
        }
        break;
    case 4:
        if (dia <= 20)
        {
            printf("Aries\n");
        } else {
            printf("Touro\n");
        }
        break;
    case 5:
        if (dia <= 20)
        {
            printf("Touro\n");
        } else {
            printf("Gemeos\n");
        }
        break;
    case 6:
        if (dia <= 20)
        {
            printf("Gemeos\n");
        } else {
            printf("Cancer\n");
        }
        break;
    case 7:
        if (dia <= 21)
        {
            printf("Cancer\n");
        } else {
            printf("Leao\n");
        }
        break;
    case 8:
        if (dia <= 22)
        {
            printf("Leao\n");
        } else {
            printf("Virgem\n");
        }
        break;
    case 9:
        if (dia <= 22)
        {
            printf("Virgem\n");
        } else {
            printf("Libra\n");
        }
        break;
    case 10:
        if (dia <= 22)
        {
            printf("Libra\n");
        } else {
            printf("Escorpiao\n");
        }
        break;
    case 11:
        if (dia <= 21)
        {
            printf("Escorpiao\n");
        } else {
            printf("Sagitario\n");
        }
        break;
    case 12:
        if (dia <= 21)
        {
            printf("Sagitario\n");
        } else {
            printf("Capricornio\n");
        }
        break;
    }
    return 0;
}