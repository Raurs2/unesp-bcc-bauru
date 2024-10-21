#include <stdio.h>
#include <math.h>

int main() {
    int duration, hrs, min, seg;
    scanf("%d", &duration);
    min = duration/60;
    seg = duration%60;
    hrs = min/60;
    min = min%60;
    printf("%d:%d:%d\n", hrs, min, seg);
    return 0;
}