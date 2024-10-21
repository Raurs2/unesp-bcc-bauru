#include <stdio.h>
#include <math.h>

int main() {
    int a, n, sum=0, i = 1;

        scanf("%d %d",&a, &n);

        while (n <= a) scanf("%d", &n);
        
       do
        {
            sum +=a;
            a++;
            if (sum <= n) i++;
        }  while (sum <= n);
        
        printf("%d\n", i);
    return 0;    
}