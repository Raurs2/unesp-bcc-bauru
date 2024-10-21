#include <stdio.h>

 void absoluto(float *n1) {
    if (*n1 < 0) *n1 =  -*n1;
}

int main() {
    float n1;
    do
    {
        scanf("%f", &n1);
        if ((int)(n1) == 0) break;
        absoluto(&n1);
        printf("%f\n\n", n1);
    } while (1);
    

    return 0;    
}