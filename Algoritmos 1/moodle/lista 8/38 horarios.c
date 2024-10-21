#include <stdio.h>
#include <math.h>
int horarios(int h1, int m1, int s1, int h2, int m2, int s2) {
    int hf, mf, sf;
    hf = h2 - h1;
    mf = m2 - m1;
    sf = s2 - s1;
    return sf + (mf*60) + (hf*3600);
}
int main() {
    int h1, h2, m1, m2, s1, s2;
    do
    {
        scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
        if (h1 == 0) break;
        printf("dif %d\n\n", horarios(h1, m1, s1, h2, m2, s2));
    } while (1);
    
    return 0;
}