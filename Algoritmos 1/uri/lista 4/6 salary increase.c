#include <stdio.h>
#include <math.h>

int main() {
    float salary, increase, newSalary;
    int percentage;

    scanf("%f", &salary);

    if (salary >= 0 && salary <= 400)
    {
        newSalary = salary * 1.15;
        increase = salary * 0.15;
        percentage = 15;
    } else if (salary > 400 && salary <= 800)
    {
        newSalary = salary * 1.12;
        increase = salary * 0.12;
        percentage = 12;
    } else if (salary > 800 && salary <= 1200)
    {
        newSalary = salary * 1.10;
        increase = salary * 0.10;
        percentage = 10;
    } else if (salary > 1200 && salary <= 2000)
    {
        newSalary = salary * 1.07;
        increase = salary * 0.07;
        percentage = 7;
    } else {
        newSalary = salary * 1.04;
        increase = salary * 0.04;
        percentage = 4;
    }
    
    printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %d %%\n", newSalary, increase, percentage);
    
    return 0;
}