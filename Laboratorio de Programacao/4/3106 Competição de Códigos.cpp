#include <string.h> 
#include <stdio.h> 

/*
    fiz um for e escaniei os alunos de cada universidade dps dividi o max de equipes e adicionei pra o somatorio multiplicando por 3
    para ter o valor de alunos.
*/

int main(){ 
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        a /= 3;
        sum += a * 3;
    }
    printf("%d\n", sum);
    return 0;
}