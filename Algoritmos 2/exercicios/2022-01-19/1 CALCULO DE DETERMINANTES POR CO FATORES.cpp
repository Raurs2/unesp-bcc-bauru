#include<stdio.h>

#define MAX 100

int det(int a[MAX][MAX], int n)
{
    int det = 0, i = 1;
    for (int j = 0; j < n; j++)
    {
        if (n % 2 == 0)
        {
            det -= a[i][j] * 
        } else
        {

        }
        
    }
    
    
}

int main()
{
    int n, a[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    
    
    return 0;
}
