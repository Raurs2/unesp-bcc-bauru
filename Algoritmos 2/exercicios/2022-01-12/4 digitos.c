#include <stdio.h>
#include <stdlib.h>

int Digitos(int N){
    int cont = 1;
    while (abs(N) > 9) {
        N = N / 10;
        cont++;
    }
    return cont;
}

int DigitosR(int n)
{
    if (n < 9) return 1;
    return 1 + DigitosR(n / 10);
}

int main(){
    printf("it %d\n", Digitos(111));
    printf("recu %d\n", Digitos(111));
}    
    
