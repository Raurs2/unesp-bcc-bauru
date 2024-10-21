#include <string.h> 
#include <stdio.h> 

/*
    eu testei se os alunos nao chegaram atrasados e dps se o tanto que chegou for maior ou igual ao min printo YES senao NO
*/

int main(){ 
    int alum, min;
    scanf("%d %d", &alum, &min);

    int a, chegou = 0;
    for (int i = 0; i < alum; i++)
    {
        scanf("%d", &a);
        if (a <= 0) chegou++;
        
    }

    if (chegou >= min) printf("YES\n");
    else printf("NO\n");

    return 0;
}