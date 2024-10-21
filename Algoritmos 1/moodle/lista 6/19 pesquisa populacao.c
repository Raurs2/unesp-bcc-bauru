#include <stdio.h>
#include <math.h>

int main() {
    int sex, eyes, hair, age, n, maior, fem = 0, i;

    scanf("%d", &n);
        
    for ( i = 1; i <= n; i++)
    {
        printf("[1] homem [2] mulher\n");
        scanf("%d", &sex);
        printf("[1] azul [2] verde [3] castanho\n");
        scanf("%d", &eyes);
        printf("[1] loiro [2] castanho [3] preto\n");
        scanf("%d", &hair);
        printf("idade\n");
        scanf("%d", &age);
        
        if (i == 1) maior = age;
        if (age > maior) maior = age;
        if (sex = 2 && age >= 18 && age <= 35 && eyes == 2 && hair == 1) fem++;

    }

    printf("Maior = %d\n fem 18-35 verd loiro = %d", maior, fem*100/n);
    
    return 0;    
}