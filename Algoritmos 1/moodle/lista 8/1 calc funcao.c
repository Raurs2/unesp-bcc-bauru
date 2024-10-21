#include <stdio.h>

int f1(int k, int l) {
if (k > l) return 1;
if (k == l) return 0;
return (-1);
}

int main() {
    int a, b, c;
    a = f1(2, 7);
    b = f1(3, 3) + f1(6, 4) + f1(2, 7);
    c = f1(2*f1(1,6),5*f1(8,2)+2*f1(1,1));
    printf("a = %d\nb = %d\nc = %d\n", a, b, c);
    return 0;    
}