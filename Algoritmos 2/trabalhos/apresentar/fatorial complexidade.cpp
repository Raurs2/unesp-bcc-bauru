#include <stdio.h>

double fat(int n)
{
    if (n <= 1) // O(1)
        return 1; // O(1)
    return n * fat(n-1); // 0(N!)
}

int main()
{
    printf("%.0lf", fat(5));
    return 0;
}
