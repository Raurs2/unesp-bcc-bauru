#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int main()
{
    int n, i;
    double b[max], sum, a[max];

    do
    {
        scanf("%d", &n);
        srand(time(NULL));
        for ( i = 0; i < n; i++) {
            scanf("%lf", &b[i]);
            a[i] = rand() % 100 + 1;
        }

        for ( i = 0; i < n; i++)
        {
            sum += b[i] * a[i] * i;
        }
        
        printf("result = %.2lf", sum);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
