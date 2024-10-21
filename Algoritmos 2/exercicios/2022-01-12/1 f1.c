#include <stdio.h>
#include <stdlib.h>

int f1(int n) {
    if (n == 0)
        return (1);
    return(n * f1(n-1));
}

int main(){
    printf("0 - %d\n", f1(0));
    printf("1 - %d\n", f1(1));
    printf("5 - %d\n", f1(5));
}    
    
/*
a) f1(0) resultou em 1 e teve 1 chamada
b) f1(1) resultou em 1 e teve 2 chamadas
c) f1(5) resultou em 5 e teve 6 chamadas
*/