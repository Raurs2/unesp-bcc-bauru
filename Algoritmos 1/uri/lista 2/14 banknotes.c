#include <stdio.h>
#include <math.h>

/*
    esse programa a gente ja fez em algoritmo 1, minha ideia foi utilizar o modulo, eu divido para retirar quantas notas tem e uso o modulo para colocar o resto na variavel 
*/

int main() {
    int v, n100, n50, n20, n10, n5, n2, n1, oldV;
    scanf("%d", &v);
    oldV = v;
    n100 = v / 100;
    v = v % 100;
    n50 = v/50;
    v = v%50;
    n20 = v/20;
    v = v%20;
    n10 = v/10;
    v = v%10;
    n5 = v/5;
    v = v%5;
    n2 = v/2;
    v = v%2;
    n1 = v/1;
    v = v%1;
    printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", oldV, n100, n50, n20, n10, n5, n2, n1);
    return 0;
}