#include <stdio.h>
#include <math.h>

int main() {
    int spentTime, averageSpeed, distance;
    float spentFuel;
    scanf("%d %d", &spentTime, &averageSpeed);
    distance = averageSpeed * spentTime;
    spentFuel = distance / 12.0;
    printf("%.3f\n", spentFuel);
    return 0;
}