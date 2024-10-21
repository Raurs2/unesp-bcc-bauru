#include <stdio.h>
#include <stdlib.h>

#define max 5

int main()
{
    int n, i;
    float a[max], avr, up, down, razao, big, small;

    do
    {
        avr = up = down = 0;
        for ( i = 0; i < max; i++) {
            scanf("%f", &a[i]);
            avr += a[i];
        }
        avr /= max;

        for ( i = 0; i < max; i++)
        {
            if (a[i] < avr) down++;
            else up++;
        }
        down *= 100 / max;
        up *= 100 / max;
        
        big = small = a[0];
        for ( i = 0; i < max; i++)
        {
            if (a[i] > big) big = a[i];
            if (a[i] < small) small = a[i];
        }
        razao = big/small;

        printf("Media = %.2f\nAcima = %.2f%% Abaixo = %.2f%%\nmaior = %.2f menor = %.2f\nRazao = %.2f", avr, up, down, big, small, razao);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
