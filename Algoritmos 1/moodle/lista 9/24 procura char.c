#include <stdio.h>
#include <stdlib.h>

#define max 10


int main()
{
    int i, n;
    char v[max], c;

    do
    {
        c = ' ';
        scanf("%c", &c);

        for (i = 0; i < max; i++)
        {
            scanf("%c", &v[i]);

            if (v[i] == c) {
                printf("Char encontrado!");
                break;
            }
        }

        
        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
