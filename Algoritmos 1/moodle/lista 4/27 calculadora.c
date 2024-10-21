#include <stdio.h>
#include <math.h>
int main() {
    int op;
    float n1, n2, n;
    printf("[1]SOMA\n[2]PRODUTO\n[3]RAIZ QUADRADA\n[4]SAIR\n");
    scanf("%d", &op);
    if (op == 4)
    {
        return 0;
    } else {
        printf("n1, n2: ");
        scanf("%f %f", &n1, &n2);

        switch (op)
        {
        case 1:
            n = n1 + n2;
            break;
        case 2:
            n = n1 * n2;
            break;
        case 3:
            n = sqrt(n1);
        }
        printf("Resultado = %.2f", n);
    }
    return 0;
}