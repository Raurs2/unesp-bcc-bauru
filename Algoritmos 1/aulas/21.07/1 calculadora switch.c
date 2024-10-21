#include <stdio.h>
#include <math.h>

int main() {
    float n1, n2, r;
    char op;
    scanf("%f %f %c", &n1, &n2, &op);

    switch (op)
    {
    case '+':
        r = n1 + n2;
        break;
    case '-':
        r = n1 - n2;
        break;
    case '/':
        r = n1 / n2;
        break;
    case '*':
        r = n1 * n2;
        break;
    default:
        break;
    }
    printf("%.2f %c %.2f = %.2f", n1, op, n2, r);
    return 0;
}