#include <stdio.h>
#include <math.h>
int main() {
    int graus;
    scanf("%d", &graus);
    if (graus >= 0 && graus <= 90 || graus >= 0 && graus <= -90)
    {
        printf("Q1");
    } else if (graus > 90 && graus <= 180 || graus > -90 && graus <= -180)
    {
        printf("Q2");
    } else if (graus > 180 && graus <= 270 || graus > -180 && graus <= -270)
    {
        printf("Q3");
    } else if (graus > 270 && graus <= 360 || graus > -270 && graus <= -360)
    {
        printf("Q4");
    }
    return 0;
}