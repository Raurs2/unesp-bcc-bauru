#include <stdio.h>

#define MAX 100

int main() {
    int i, j, k = 0, n;
    double a[MAX][MAX], r = 0;
    

    scanf("%d", &n);
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
            if (j <= k) r += a[i][j];
        }
        k++;
    }
         
    printf("%.1lf\n", r);

    return 0;
}
