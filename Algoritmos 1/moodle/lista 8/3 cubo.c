#include <stdio.h>

int cubo(int a) {
return a*a*a;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", cubo(x));
    return 0;    
}