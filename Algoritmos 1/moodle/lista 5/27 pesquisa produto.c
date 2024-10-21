#include <stdio.h>
#include <math.h>

int main()
{
    int i, yesM = 0, yesF = 0, noM = 0, noF = 0, tot;
    int sex, answer;

    for (i = 1; i <= 15; i++)
    {
        scanf("%d %d", &sex, &answer);
        if (sex == 1 && answer == 2)
        {
            noM++;
        }
        if (sex == 1 && answer == 1)
        {
            yesM++;
        }
        if (sex == 2 && answer == 1)
        {
            yesF++;
        }
    }
    printf("SIM: %d\nMASC NAO: %d%%", yesF + yesM, (int)(noM * 100.0 / 15.0));
    
    return 0;
}