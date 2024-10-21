#include <stdio.h>

int main()
{
    int x = 1, y = 2, n;

    scanf("%d", &n);

    if (n == 2 || n== 3)
    {
        printf("NO SOLUTION\n");
    } else if (n == 4){
        printf("2 4 1 3\n");
        
        
    } else
    {
        while (x <= n)
        {
            printf("%d", x);
            if (n != 1)
            {
                printf(" ");
            }
            
            x += 2;
        }
        while (y <= n)
        {
           printf("%d", y); 
            y += 2; 
            if (y <= n)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    

    
    
    return 0;
}