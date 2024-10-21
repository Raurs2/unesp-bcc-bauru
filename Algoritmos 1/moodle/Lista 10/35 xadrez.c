#include <stdio.h>
#include <stdlib.h>

#define lin 2
#define col 2
#define name 20

int main() {
    int i, j, n;
    char a[lin][col];
    do
    {
        
        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                scanf("%s", &a[i][j]);
            }
            
        }

        for ( i = 0; i < lin; i++)
        {
            for ( j = 0; j < col; j++)
            {
                printf("%s ", a[i][j]);
            }
            printf("\n");
        }
        
        
        printf("\nContinuar?\n");
        scanf("%d", &n);
        system("cls");
    } while (n != 0);
    
    return 0;
}