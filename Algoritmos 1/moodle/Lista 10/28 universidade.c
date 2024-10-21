#include <stdio.h>
#include <stdlib.h>

#define lin 50
#define col 4

int main() {
    int a[lin][col], i, j, n, sex, curso, avr, matri;
    do
    {
        avr = 0;

        scanf("%d", &n);
        if (n == 0) break;
        printf("matri, sexo, curso, media\n");
        for ( i = 0; i < n; i++)
        {
            for ( j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Qual Curso e sexo?\n");
        scanf("%d %d", &curso, &sex);
        for ( i = 0; i < n; i++)
        {
            if (a[i][1] == sex &&a[i][2] == curso && a[i][3] > avr) {
            avr = a[i][3];
            matri = a[i][0];
            }
        }
        
        printf("aluno de matricula %d do curso %d de sexo %d possui maior media de %d\n", matri, curso, sex, avr);
    } while (n =! 0);
    
    
    return 0;
}