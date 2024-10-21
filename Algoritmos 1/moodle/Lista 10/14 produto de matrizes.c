#include <stdio.h>
#define LINA 1
#define COLA 2
#define LINB 2
#define COLB 3

void fillMatrix(int lin, int col, int m[][]){
    int i, j;
    for ( i = 0; i < lin; i++)
        for ( j = 0; j < col; j++)
            scanf("%d", &m[i][j]);
}

void printMatrix(int lin, int col, int m[][]){
    int i, j;
    for ( i = 0; i < lin; i++) {
        for ( j = 0; j < col; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

}

int main() {
    int a[LINA][COLA], i, j, sum = 0, k, b[LINB][COLB], c[LINA][COLB];
    do
    {
        fillMatrix(LINA, COLA, a);
        fillMatrix(LINB, COLB, b);
        printMatrix(LINA, COLA, a);
        printMatrix(LINB, COLB, b);
        printf("Continuar != 0\n");
        scanf("%d", &k);
    } while (k != 0);
    
}