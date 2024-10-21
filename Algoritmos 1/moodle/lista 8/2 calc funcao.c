#include <stdio.h>

int f2 (int a, int b, int c) {
if (a > b && b > c)
return a;
if (a < b && b < c)
return a;
return (a+b+c)/2;
}

int main() {
    int a, b, c, d;
    a = f2(10,8,-1);
    b = f2(1,4,5);
    c = f2(5,2,-2);
    d = f2(4*f2(10,5,-1),6*f2(1,3,5)-1,2-f2(100,1,3));
    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
    return 0;    
}