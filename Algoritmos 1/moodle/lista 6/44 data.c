#include<stdio.h>

int main()
{
    int a, m, d;
    scanf("%d %d %d", &d, &m, &a);

    if (a % 400 == 0) printf("%d bissexto\n", a);
    else if (a % 4 == 0 && a % 100 != 0) printf("%d bissexto\n", a);
    printf("%d de", d);
    switch (m)
    {
    case 1:
        printf(" Janeiro ");
        break;
    case 2:
        printf(" Fevereiro ");
        break;
    case 3:
        printf(" Março ");
        break;
    case 4:
        printf(" Abril ");
        break;
    case 5:
        printf(" Maio ");
        break;
    case 6:
        printf(" Junho ");
        break;
    case 7:
        printf(" Julho ");
        break;
    case 8:
        printf(" Agosto ");
        break;
    case 9:
        printf(" Setembro ");
        break;
    case 10:
        printf(" Outubro ");
        break;
    case 11:
        printf(" Novembro ");
        break;
    case 12:
        printf(" Dezembro ");
        break;
    }
    printf("de %d", a);
    return 0;
}
