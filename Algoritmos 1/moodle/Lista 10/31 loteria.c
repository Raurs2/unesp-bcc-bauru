#include <stdio.h>
#include <stdlib.h>

#define lin 3
#define col 13

int main() {
    int i, j, n, vf, v;
    int a[lin][col];
    do
    {
        scanf("%d", &v);
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                scanf("%d", &a[i][j]);
            }
            
        }
        
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}