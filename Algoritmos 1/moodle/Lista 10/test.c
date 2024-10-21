#include <stdio.h>

int main()
{
    float m1[3][15];
    int m2[3][16];
    char m3[3][4][10];
    long int m4[5][5][5][5];
    printf("float m1[3][15]: %d Elementos %zu Bytes\n", 3*15, sizeof(m1));
    printf("m2[3][16]: %d Elementos %zu Bytes\n", 3*16, sizeof(m2));
    printf("m3[3][4][10]: %d Elementos %zu Bytes\n", 3*4*10, sizeof(m3));
    printf("m4[5][5][5][5]: %d Elementos %zu Bytes\n", 5*5*5*5, sizeof(m4));
    return 0;
}
