#include <stdio.h>

int main()
{
    int birthYear, NowYear;

    scanf("%d %d", &birthYear, &NowYear);

    printf("IDADE: %d\nEM SEMANAS: %d\n", NowYear - birthYear, ( NowYear - birthYear) * 365 / 7);
    return 0;
}
