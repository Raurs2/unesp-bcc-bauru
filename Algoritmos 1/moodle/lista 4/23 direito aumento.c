#include <stdio.h>
#include <math.h>
int main() {
    float sal;
    scanf("%f", &sal);
    if (sal < 840)
    {
        sal = sal * 1.13;
    } else {
        printf("sem aumento\n");
    }
    printf("sal = %.2f", sal);
    return 0;
}