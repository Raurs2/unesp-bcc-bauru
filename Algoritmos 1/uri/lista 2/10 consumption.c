#include <stdio.h>

int main() {
    int totKm;
    float spentFuel, average;
    scanf("%d %f", &totKm, &spentFuel);
    average = totKm / spentFuel;
    printf("%.3f km/l\n", average);
    return 0;
}