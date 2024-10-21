#include <stdio.h>

#define MAX 12

int main() {
    int i, j, k = 0;
    char op;
    double a[MAX][MAX], r = 0;
    

    scanf("%c", &op);

    for ( i = 0; i < MAX; i++) {
        for ( j = 0; j < MAX; j++) {
            scanf("%lf", &a[i][j]);
            if (j < k) r += a[i][j];
        }
        k++;
    }
         
    if (op == 'M') r /= 66.0;
    printf("%.1lf\n", r);

    return 0;
}
