
#include<stdio.h>

int ff (int n) {
if (n == 1)
return 1;
if (n % 2 == 0)
return ff (n/2);
return ff ((n-1)/2) + ff ((n+1)/2);
}

int main()
{
    printf("%d\n", ff(7));
 
    return 0;
}

/* Qual o resultado da execução do programa abaixo?
   3

*/