#include <stdio.h>
#include <stdlib.h>

#define max 100

int main()
{
    int n, i, j = 1, ea, eb, pos_a = 0, pos_b = 0, aaa;
    int a[max], b[max], c[200];

    do
    {
        printf("Elementos em a\n");
        scanf("%d", &ea);
        for ( i = 0; i < ea; i++)
            scanf("%d", &a[i]);

        printf("Elementos em b\n");
        scanf("%d", &eb);
        for ( i = 0; i < eb; i++)
            scanf("%d", &b[i]);
        i = 0;
        aaa = ea + eb;
        while (ea != 0 || eb != 0)
        {
            if (ea > 0){
                c[i++] = a[pos_a];
                pos_a++;
                ea--;
            }
            if (eb > 0) {
                c[i++] = b[pos_b];
                pos_b++;
                eb--;
            }
        }
        for ( i = 0; i < aaa; i++)
        {
            printf("%d ", c[i]);
        }
        
        
        printf("\n\nContinuar? [0] parar\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);

    return 0;
}
