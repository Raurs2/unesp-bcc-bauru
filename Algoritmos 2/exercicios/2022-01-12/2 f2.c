#include <stdio.h>
#include <stdlib.h>

int f2(int n) {
if (n == 0)
    printf("Zero ");
else {
    printf("%d ",n);
    printf("%d ",n);
    f2(n-1);
}
}

int main(){
    f2(0);
    f2(1);
    f2(5);
}    
    
/*
a) f2(0) resultou em Zero e teve 1 chamada
b) f2(1) resultou em 1 1 Zero e teve 2 chamadas
c) f2(5) resultou em 5 5 4 4 3 3 2 2 1 1 Zero e teve 6 chamadas
*/