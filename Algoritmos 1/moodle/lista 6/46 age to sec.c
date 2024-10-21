#include<stdio.h>

int main()
{
    int a1, a2;
    do
    {
        scanf("%d %d", &a1, &a2);
        printf("1 mes %d, dia %d, hr %d, min %d\n", a1*365/30, a1*365, a1*365*24, a1*365*24*60);
        printf("2 mes %d, dia %d, hr %d, min %d\n", a2*365/30, a2*365, a2*365*24, a2*365*24*60);
        printf("1-2 mes %d, dia %d, hr %d, min %d\n", a1*365/30-a2*365/30, a1*365-a2*365, a1*365*24-a2*365*24, a1*365*24*60-a2*365*24*60);
    } while (a1 != a2);
    

    return 0;
}
