#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 primeiro fiz a hipotenusa e multipliquei pela qtd de degraus, depois calculei 
 a area total da superficie da rampa
*/

int main()
{
    int n, a, b, c;
    double r;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%d %d %d", &a, &b, &c);
        r = n * sqrt(a * a + b * b);
        printf("%.4lf\n", (c*r) / (100.0 * 100));
    }
    
    
    return 0;
}