#include <stdio.h>

typedef struct hm {
    float hr, min;
} hm;

int main()
{
    hm hrMin;
    scanf("%f", &hrMin.min);
    hrMin.hr = hrMin.min / 60;
    printf("%.0fmin = %.1fhrs", hrMin.min, hrMin.hr);
    return 0;
}
