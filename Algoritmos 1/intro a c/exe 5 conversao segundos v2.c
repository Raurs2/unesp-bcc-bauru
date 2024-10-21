#include<stdio.h>
int main()
{
    int hr, min, seg;
    printf("horas, min, seg\n");
    scanf("%d %d %d", &hr, &min, &seg);
    printf("%d:%d:%d\n", hr, min, seg);
    min += hr * 60;
    seg += min * 60;
    printf("segundos total: %d", seg);
    return 0;
}
