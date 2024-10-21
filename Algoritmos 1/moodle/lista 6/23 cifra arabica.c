#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    do
    {
        if (n / 1000 >0) {
            printf("M");
            n -= 1000;
        } else if (n / 500 >0) {
            printf("D");
            n -= 500;
        } else if (n % 1000 / 100 == 4) {
            printf("CD");
            n -=400;
        } else if (n / 100 >0) {
            printf("C");
            n -= 100;
        } else if (n / 50 >0) {
            printf("L");
            n -= 50;
        } else if (n / 10 >0) {
            printf("X");
            n -= 10;
        } else if (n / 5 >0) {
            printf("V");
            n -= 5;
        } else if (n / 1 >0) {
            printf("I");
            n -= 1;
        }
    } while (n != 0);
    
    
    return 0;    
}