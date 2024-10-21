#include <stdio.h>
#include <conio.h>
void raizMilhar() {
    int n[3], i;
    for ( i = 1000; i <= 9999; i++)
    {
        n[0] = i / 100;
        n[1] = i % 100;
        n[2] = n[0] + n[1];
        n[2] *= n[2];
        if (i == n[2]) printf("raiz de %d = %d + %d\n", i, n[0], n[1]);
    }
}
int main(){
    raizMilhar();
}