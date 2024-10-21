#include <stdio.h>

int main()
{
    int test, n;
    
    scanf("%d", &test);

    do
    {
        scanf("%d", &n);

        if (n == 0)
        {
            printf("NULL\n");
        } else {
            if (n % 2 == 0)
            {
                printf("EVEN ");
            } else {
                printf("ODD ");
            }

            if (n > 0)
            {
                printf("POSITIVE\n");
            } else {
                printf("NEGATIVE\n");
            }
            
        }

        test--;
        
    } while (test > 0);
    
    return 0;
}
