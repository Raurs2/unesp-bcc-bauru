#include <stdio.h>

void multi(int n, int i, int j) {
    int a = 0;
    while (n != 0)
    {
        if (a % i == 0 || a % j == 0){
            printf("%d ", a);
            n--;
        } 
        a++;
    }
}

int main() {
    int n, i, j;
    scanf("%d %d %d", &n, &i, &j);
    multi(n, i, j);
    return 0;    
}