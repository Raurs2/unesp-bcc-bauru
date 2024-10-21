#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 25

int main()
{
    int n, i;
    int b[max], big, small;

    do
    {
        srand(time(NULL));
        for ( i = 0; i < max; i++) {
            b[i] = rand() % 100 + 1;
        }
        big = small = b[0];
        for ( i = 1; i < max; i++)
        {
            if (big < b[i]) big = b[i];
            if (small > b[i]) small = b[i];
        }

        printf("maior = %d\nMenor = %d\n", big, small);

        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
