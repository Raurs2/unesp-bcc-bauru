#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int main() {
    int i, j;
    float custo[MAX][MAX], armazem[MAX][MAX], maior; 
    for ( i = 0; i < MAX; i++)
    {
        
        for ( j = 0; j < MAX; j++)
        {
            scanf("%f", &armazem[i][j]);
            maior = armazem[i][1];
            
        }
        scanf("%f", &custo[i][0]);
        custo[i][1] = 0;
        custo[i][2] = 1;
    }
    
    printf("            Produto 1 produto 2 produto 3");
    for ( i = 0; i < MAX; i++)
    {
        printf("\nArmazem %d: ", i);
        for ( j = 0; j < MAX; j++)
        {
            printf("%f ", armazem[i][j]);
            if (armazem[i][1] > maior) maior = armazem[i][1];
            custo[i][1] += custo[j][0] * armazem[i][j];
            
        }
        custo[0][2] *= custo[i][1];
        printf("\n");
    }
    for ( i = 0; i < MAX; i++)
    {
        printf("Custo no armazem %d: %f\n", i, custo[i][1]);
    }
    printf("\nCusto total: %f", custo[0][2]);
    printf("\n\nMaior: %f", maior);
    return 0;
}