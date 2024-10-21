#include<stdio.h>

int main()
{
    int x0, y0, x, y, k, route, min, x_now, y_now, i;

        scanf("%d %d", &x0, &y0);

        scanf("%d %d", &x, &y);

        scanf("%d", &k);
        min = x_now = y_now = 0;
        
        for ( i = 1; i <= k; i++)
        {
            scanf("%d", &route);

            if (route == 1) y_now++;
            if (route == 2) y_now--;
            if (route == 3) x_now++;
            if (route == 4) x_now--;
            
            if (x_now <= x+1 && x_now >= x-1 && y_now <= y+1 && y_now >= y-1)
                min++;
            
        }
        

        printf("%d\n\n", min);
    //1 norte, 2 sul, 3 lest, 4 oest
    
    
    return 0;
}
