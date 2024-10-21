#include <stdio.h>

#define line 12
#define col 12

int main()
{
    int i, j, n;
    double a[line][col], r = 0;
    char op;

    scanf("%d", &n);
    scanf(" %c", &op);
    for ( i = 0; i < line; i++)
        for ( j = 0; j < col; j++)
            scanf("%lf", &a[i][j]);

    for ( i = 0; i < col; i++)
        r += a[n][i];
    if (op = 'M')
        r /= col;

    printf("%.1lf\n", r);
    return 0;
}
