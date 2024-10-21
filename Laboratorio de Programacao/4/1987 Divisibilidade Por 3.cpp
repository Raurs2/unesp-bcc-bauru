#include <string.h> 
#include <stdio.h> 
/*
    coloquei scanf no while pra parar no EOF, fiz um while somando cada casa do numero digitado
    e depois um teste pra ver se o somatorio é dificil por 3 ou nao.
*/

int main(){ 
    long unsigned int num;
    int sum = 0;
    int n;

    while (scanf("%d %d", &n, &num) != EOF)
    {
        sum = 0;

        while (num)
        {
            sum += num % 10;
            num /= 10;  
        }
        
        if (sum % 3 == 0) printf("%d sim\n", sum);
        else printf("%d nao\n", sum);
    } 

    return 0;
}