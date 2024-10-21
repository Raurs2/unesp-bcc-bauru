#include <stdio.h>
#include <stdlib.h>

#define lin 26
#define col 10

int main() {
    int a[lin][col], i, j, n, muni, pop, avr, estado;
    do
    {
        pop = 0;
        avr = 0;
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] > pop) {
                    pop = a[i][j];
                    muni = j+1;
                    estado = i+1;
                }
            }
            avr += a[i][0];
        }
        avr /= lin;
        printf("Estado %d Municipio %d de pop. %d mais populoso\nMedia pop das capitais eh: %d\n", estado, muni, pop, avr);
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}