#include<stdio.h>

int g(int a, int m) {
    if (m <= 2) return a - 1;
    else return a;
}

int f(int m) {
    if (m <= 2) return m + 13;
    else return m + 1;
}

int v(int n) {
    if (n < 36523) return 2;
    else if (n >= 36523 && n < 73048) return 1;
    else return 0;
}

int main()
{
    int a, m, d, n, ds;
    scanf("%d %d %d", &d, &m, &a);

    n = (int)(365.25 * g(a, m)) + (int)(30.6*f(m)) + d - 621049;
    ds = (n/7 - n/7) * 7 + v(n) + 1;

    switch (ds)
    {
    case 1:
        printf("dom\n");
        break;
    case 2:
        printf("seg\n");
        break;
    case 3:
        printf("ter\n");
        break;
    case 4:
        printf("quar\n");
        break;
    case 5:
        printf("quin\n");
        break;
    case 6:
        printf("sexta\n");
        break;
    case 7:
        printf("sab\n");
        break;
    
    default:
        break;
    }
    return 0;
}
