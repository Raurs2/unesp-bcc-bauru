#include <stdio.h>
#include <math.h>

int main() {
    int spentTime, averageSpeed, distance;
    float spentFuel, kml;
    scanf("%d %d %f", &spentTime, &averageSpeed, kml);
    distance = averageSpeed * spentTime;
    spentFuel = distance / kml;
    printf("%.3f\n", spentFuel);
    return 0;
}