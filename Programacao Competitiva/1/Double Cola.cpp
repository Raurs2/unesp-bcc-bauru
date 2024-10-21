#include<cstdio>
#include<math.h>

int main()
{
    long int x;
    int n = 0;

    scanf("%ld", &x);

    while (x > 5 * pow(2, n))
    {
        x -= 5 * pow(2, n);
        n++;
    }

    double y = pow(2, n);

    if (x <= 1 * y)
    {
        printf("Sheldon\n");
    }
    else if (x <= 2 * y)
    {
        printf("Leonard\n");
    }
    else if (x <= 3 * y)
    {
        printf("Penny\n");
    }
    else if (x <= 4 * y)
    {
        printf("Rajesh\n");
    }
    
    else if (x <= 5 * y)
    {
        printf("Howard\n");
    }
    
    
    return 0;
}
