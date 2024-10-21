#include <stdio.h>
#include <math.h>

int main() {
    float n;
    char c;
    scanf("%f", &n);
    if (n >= 86)
    {
        c = 'A';
    } else if (n >= 61 && n <= 85)
    {
        c = 'B';
    } else if (n >= 36 && n <= 60)
    {
        c = 'C';
    } else if (n >= 1 && n <= 35)
    {
        c = 'D';
    } else if (n == 0)
    {
        c = 'E';
    }
    
    printf("%c", c);
    return 0;
}