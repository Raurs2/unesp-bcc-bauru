#include <stdio.h>
#define TAM 12

int main() {

    int i,j;
    char t;
    double m[TAM][TAM], a = 0;

    scanf("%c",&t);

    for (i=0; i<TAM; i++) {
        for (j=0;j<TAM;j++) {
            scanf("%lf", &m[i][j]);
            if (j>i)
                a += m[i][j];
        }
    }
    if (t=='M') a /= 66.0;
    printf("%.1lf\n", a);
    return 0;
}