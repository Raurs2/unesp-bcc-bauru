#include <stdio.h>

int main()
{
    int test, pa, pb, time;
    double ga, gb;
    scanf("%d", &test);
    do
    {
        time = 0;
        scanf("%d %d %lf %lf", &pa, &pb, &ga, &gb);

            while (pa <= pb)
            {
                pa *= (ga / 100.0) + 1.0;
                pb *= (gb / 100.0) + 1.0;
                time++;

                if (time > 100)
                {
                    printf("Mais de 1 seculo.\n");
                    break;
                }
            }
            
        if (time <= 100) printf("%d anos.\n", time);

        test--;
    } while (test > 0);
    
    return 0;
}
