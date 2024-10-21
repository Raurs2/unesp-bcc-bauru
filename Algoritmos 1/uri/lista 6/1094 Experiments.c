#include <stdio.h>

int main()
{
    int test, amount = 0, frog = 0, rat = 0, rabbit = 0, n;
    char animal;
    float porRabbit, porRat, porFrog;

    scanf("%d", &test);

    do
    {
        scanf("%d %c", &n, &animal);
        
        switch (animal)
        {
        case 'C':
            rabbit += n;
            break;
        case 'R':
            rat += n;
            break;
        case 'S':
            frog += n;
            break;
        }
        amount += n;
        
        test--;
    } while (test > 0);
    porRabbit = rabbit * 100.0 / amount;
    porRat = rat * 100.0 / amount;
    porFrog = frog * 100.0 / amount;
    printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2f %%\nPercentual de ratos: %.2f %%\nPercentual de sapos: %.2f %%\n", amount, rabbit, rat, frog, porRabbit, porRat, porFrog);
    return 0;
}
