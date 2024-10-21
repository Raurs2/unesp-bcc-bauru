#include <stdio.h>
#include <math.h>

int main() {
    int ageDays, years, months;
    scanf("%d", &ageDays);
    years = ageDays/365;
    ageDays = ageDays%365;
    months = ageDays/30;
    ageDays = ageDays%30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", years, months, ageDays);
    return 0;
}