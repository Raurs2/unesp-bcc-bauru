#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, i, r, r2, r3;

    printf("x < y\n");
    scanf("%d %d", &x, &y);

    do
    {
        srand(time(NULL));
        r = rand() % (y-x+1) + x;
        r2 = rand() % (y-x+1) + x;
        r3 = rand() % (y-x+1) + x;

           
    } while (r == r2 || r2 == r3 || r == r3);
    printf("%d %d %d\n", r, r2, r3);
    
    return 0;    
}