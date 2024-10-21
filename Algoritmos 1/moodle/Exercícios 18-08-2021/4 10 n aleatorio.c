#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, i, r, r2, r3, r4, r5, r6, r7, r8, r9, r10;
    
    printf("x < y\n");
    scanf("%d %d", &x, &y);

    do
    {
        srand(time(NULL));
        r = rand() % (y-x+1) + x;
        r2 = rand() % (y-x+1) + x;
        r3 = rand() % (y-x+1) + x;
        r4 = rand() % (y-x+1) + x;
        r5 = rand() % (y-x+1) + x;
        r6 = rand() % (y-x+1) + x;
        r7 = rand() % (y-x+1) + x;
        r8 = rand() % (y-x+1) + x;
        r9 = rand() % (y-x+1) + x;
        r10 = rand() % (y-x+1) + x;

           
    } while (r == r2 || r == r3 || r == r3 || r == r4 || r == r5 || r == r6 || r == r7 || r == r8 || r == r9 || r == r10);
    printf("%d %d %d %d %d %d %d %d %d %d\n", r, r2, r3, r4, r5, r6, r7, r8, r9, r10);
    
    return 0;    
}