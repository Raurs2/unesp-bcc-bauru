#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 40

int main()
{
    int n, i;
    float a[max], b[max], sum = 0;

    do
    {
        sum = 0;
        for ( i = 0; i < max; i++) {
            scanf("%f", &a[i]);
            srand(time(NULL));
            b[i] = rand() % 100 + 1; 
        }

        for ( i = 0; i < max; i++)
        {
            sum += a[i] * b[i];            
        }

        printf("%.2f", sum);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
