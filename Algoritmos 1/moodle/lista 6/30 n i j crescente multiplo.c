#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n, i, j, a = 0;

    scanf("%d %d %d", &n, &i, &j);

    while (n != 0)
    {
        if (a % i == 0 || a % j == 0){
            printf("%d ", a);
            n--;
        } 
        a++;
    }
    
    return 0;    
}