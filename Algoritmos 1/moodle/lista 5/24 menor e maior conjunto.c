#include <stdio.h>
#include <math.h>

int main()
{
    int i, n = 0, big = 1, small = 1;
    do
    {
        scanf("%d", &n);

        if (n > big)
        {
            big = n;
        } else  if (n < small && n >= 0){
            small = n;
        }
    } while (n >= 0);
    
    printf("MAIOR: %d\nMENOR: %d\n", big, small);
    return 0;
}