#include <stdio.h>

int doisInt(int n1, int n2, int v[]) {
    int sum = 0, resto;
    do
    {
        if (n1 / n2 != 0) {
            sum++;
            n1 -= n2;
        }
        resto = n1;
    } while (n1 / n2 != 0);
    
    v[0] = sum;
    v[1] = resto;
}

int main() {
    int x, y, v[2];
    do
    {
        scanf("%d %d", &x, &y);
        if (x == 0 || y == 0) break;
        doisInt(x, y, v);
        printf("%d e %d\n", v[0], v[1]);
    } while (1);
    
    return 0;    
}