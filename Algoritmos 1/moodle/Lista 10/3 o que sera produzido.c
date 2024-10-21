#include <stdio.h>

int main()
{
    int i, j, k, C[3][2] = {{1, 3}, {2, 1}, {1, 4}};
    int A[2][3] = {{1, 2, 1}, {3, 1, 4}};
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++) {
    for (k = 0; k < 3; k++)
    printf ("%2d ",A[i][k]+C[k][j]);
    printf ("\n");
    }
    return 0;
}
