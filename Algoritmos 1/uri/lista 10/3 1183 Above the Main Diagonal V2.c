#include <stdio.h>

#define MAX 12

int main() {
    int i, j;
    char op;
    double a[MAX][MAX], r = 0;
    

    scanf("%c", &op);

    for ( i = 0; i < MAX; i++) {
        for ( j = 0; j < MAX; j++) {
            scanf("%lf", &a[i][j]);
            if (j > i) r += a[i][j];
        }
    }
         
    if (op == 'M') r /= 66.0;
    printf("%.1lf\n", r);

    return 0;
}
