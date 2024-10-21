#include <stdio.h>

int main()
{
    int test, n, in = 0, out = 0;
    
    scanf("%d", &test);

    do
    {
        scanf("%d", &n);
        
        if (n >= 10 && n <= 20)
        {
            in += 1;
        } else {
            out += 1;
        }

        test--;
        
    } while (test > 0);
    
    
    
    printf("%d in\n%d out\n", in, out);
    
    return 0;
}
