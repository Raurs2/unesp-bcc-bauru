#include <stdio.h>
#include <math.h>

int main() {
    float n1, n2, n3, n4, avr, n5;
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    avr = ((n1 * 2) + (n2 * 3) + (n3 * 4) + (n4 * 1)) / (2  + 3 + 4 + 1);
    printf("Media: %.1f\n", avr);
    if (avr >= 7)
    {
        printf("Aluno aprovado.\n");
    } else if (avr < 7 && avr >= 5)
    {
        printf("Aluno em exame.\n");
        scanf("%f", &n5);
        printf("Nota do exame: %.1f\n", n5);
        avr = (avr + n5) / 2;
        if (avr >= 5)
        {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", avr);
        
    } else {
        printf("Aluno reprovado.\n");
    }
    
    
    return 0;
}