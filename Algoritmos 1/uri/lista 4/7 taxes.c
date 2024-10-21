#include <stdio.h>
#include <math.h>

int main() {
    float n, i;
    scanf("%f", &n);
    if (n >= 0 && n <= 2000)
    {
        printf("Isento");
        return 0;
    } else if (n > 2000 && n <= 3000)
    {
        i = n - 2000;
        i = i * 0.08;
    } else if (n > 3000 && n <= 4500)
    {
        i = n - 3000;
        i = i * 0.18 + 80;
    } else
    {
        i = n - 4500;
        i = i * 0.28 + 350;
    }
    printf("R$ %.2f\n", i);
    return 0;
}