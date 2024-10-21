#include <stdio.h>
#include <math.h>

int cent(int n, int x) {
    int n1;
    n1 = n / x;
    return n1;
}

int dez(int n) {
    int n1;
    n1 = n % 100 / 10;
    return n1;
}

int uni(int n) {
    int n1;
    n1 = n % 10;
    return n1;
}

int main() {
    int n1[4], n2[4], i, nf[4], nDigits;
    scanf("%d %d", &n1[0], &n2[0]);

    n1[1] = cent(n1[0], 100);
    n1[2] = dez(n1[0]);
    n1[3] = uni(n1[0]);

    n2[1] = cent(n2[0], 100);
    n2[2] = dez(n2[0]);
    n2[3] = uni(n2[0]);

    nf[0] = n1[0] * n2[3];
    nf[1] = n1[0] * n2[2];
    nf[2] = n1[0] * n2[1];
    nf[3] = n1[0] * n2[0];

    printf("      %d %d %d\n", n1[1], n1[2], n1[3]);
    printf("    X %d %d %d\n", n2[1], n2[2], n2[3]);
    printf("    %d %d %d %d\n", cent(nf[0], 1000), cent(nf[0]%1000, 100), dez(nf[0]), uni(nf[0]));
    printf("  %d %d %d %d %d\n", cent(nf[1], 10000), cent(nf[1], 1000), cent(nf[1], 100), dez(nf[1]), uni(nf[1]));
    printf("%d %d %d %d %d %d\n", cent(nf[2], 100000), cent(nf[2], 10000), cent(nf[2], 1000), cent(nf[2], 100), dez(nf[2]), uni(nf[2]));
    printf("------------\n");
    printf("%d %d %d %d %d %d\n", cent(nf[3], 100000), cent(nf[3], 10000), cent(nf[3], 1000), cent(nf[3], 100), dez(nf[3]), uni(nf[3]));
    return 0;    
}