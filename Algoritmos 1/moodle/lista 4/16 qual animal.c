#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c;
    printf("Mamifero - 1\nAve - 2\nreptil - 3\n");
    scanf("%d", &a);
    printf("quadrúpede - 1\nbípede - 2\nvoadores - 3\naquáticos - 4\nnao voador - 5\nde rapina - 6\ncom casco - 7\nsem patas - 8\ncarnivoro - 9\n");
    scanf("%d", &b);
    printf("carnívoro - 1\n herbívoro - 2\n onívoro - 3\n frutífero - 4\n tropical - 5\n polar - 6\n");
    scanf("%d", &c);
    if (a == 1)
    {
        if (b == 1)
        {
            if (b == 1)
            {
                if (c == 1)
                {
                    printf("leao");
                } else if (c == 2)
                {
                    printf("cavalo");
                }
            } else if (b == 2)
            {
                if (c == 3)
                {
                    printf("homem");
                } else if (c == 4)
                {
                    printf("macaco");
                }
            } else if (b == 3)
            {
                printf("morcego");
            } else if (b == 4)
            {
                printf("baleia");
            }
        }
        
    } else if (a == 2)
    {
        if (b == 5)
        {
            if (c == 5)
            {
                printf("avestruz");
            } else if (c == 6)
            {
                printf("pinguim");
            } else if (b == 4)
            {
                printf("pato");
            } else if (b == 6)
            {
                printf("aguia");
            }
        }
        
    } else if (a == 3)
    {
        if (b == 7)
        {
            printf("tartaruga\n");
        } else if (b == 9)
        {
            printf("rocodilo");
        } else if (b == 8)
        {
            printf("cobra");
        }
    }
    return 0;
}