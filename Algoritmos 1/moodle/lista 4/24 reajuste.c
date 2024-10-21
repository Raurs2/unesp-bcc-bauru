#include <stdio.h>
#include <math.h>
int main() {
    float sal;
    scanf("%f", &sal);
    if (sal <= 1350)
    {
        sal = sal * 1.255;
    } else {
        sal = sal * 1.1225;
    }
    printf("sal = %.2f", sal);
    return 0;
}