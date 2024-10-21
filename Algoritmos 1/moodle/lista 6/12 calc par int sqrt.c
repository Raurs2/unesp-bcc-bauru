#include <stdio.h>
#include <math.h>

int main() {
    double n;
    int raiz;
    
    do
    {
        scanf("%lf", &n);
        raiz = round(sqrt(n));

        if (raiz % 2 != 0) raiz++;
        //else if (raiz % 2 != 0) raiz--;
        printf("%d\n", raiz);
        
            
    } while (n != 0);
    
    
    
    return 0;    
}