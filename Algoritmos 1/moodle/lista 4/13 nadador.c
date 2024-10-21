#include <stdio.h>
#include <math.h>
int main() {
    int i;
    printf("idade\n");
    scanf("%d", &i);
    if (i >= 5 && i <= 7)
    {
        printf("INFANTIL A");
    } else if (i >= 8 && i <= 10)
    {
        printf("INFANTIL B");
    } else if (i >= 11 && i <= 13)
    {
        printf("JUVENIL A");
    } else if (i >= 14 && i <= 17)
    {
        printf("JUVENIL B");
    } else if (i >= 18)
    {
        printf("SENIOR");
    }
    return 0;
}
