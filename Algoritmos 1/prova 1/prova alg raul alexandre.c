#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Autor: Raul Alexandre Gonzalez Augusto

//Retorna o somatorio da funcao dada
double somatorio() {
    double i, j, s = 0;

    for (j = 1.0, i = 38.0; j <= 37.0; j++, i--)
        s +=  ((i-1)*i)/j;

    return s;
}

//faz a soma de todos os elementos da matriz
double somaMatriz(int lin, int col, double a[MAX][MAX]) {
    int i, j;
    double sum = 0;

    for ( i = 0; i < lin; i++)
        for ( j = 0; j < col; j++)
            sum += a[i][j];
    
    return sum;
}

int main()
{
    double x, a[MAX][MAX], y;
    int i, j, lin, col, n;
 
    //executa enquanto n != 0
    do
    {
        system("cls");
        x = somatorio();
        printf("somatorio = %.2lf\n\n", x);
        
        printf("Informe o m e n da matriz\n");
        scanf("%d %d", &lin, &col);

        printf("\nInforme os elementos da matriz(%d,%d)\n", lin, col);
        for ( i = 0; i < lin; i++)
            for ( j = 0; j < col; j++)
                scanf("%lf", &a[i][j]);

        y = somaMatriz(lin, col, a);
        printf("\nSoma dos elementos da matriz = %.2lf\n", y);

        printf("\nDeseja continuar? (0 - para parar)\n");
        scanf("%d", &n);
    } while (n != 0);
    
    return 0;
}