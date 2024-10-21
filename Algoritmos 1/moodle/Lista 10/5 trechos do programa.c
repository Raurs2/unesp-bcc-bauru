#include <stdio.h>

int main () {
    double somaE, somaF, A[5][6];
    for ( i = 0, somaE = 0; i < 5; i++)
        somaE += A[i][4];
    for ( i = 0, somaF = 0; i < 6; i++)
        somaF += A[3][i];
    
    return 0;
}