#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double diagonal_para(double x, double y, double z) {
    return sqrt(x*x + y*y + z*z);
}

double area_para(double x, double y, double z) {
    return 2*x*y + 2*y*z + 2*x*z;
}

double area_tri(double x, double y) {
    return x*y/2;
}

double area_quad(double x, double y) {
    return x*y;
}

int main() {
    int n;
    double x, y, z;
    
    do
    {
        do
        {
            printf("[1] Diagonal do paralelepipedo\n[2] Area do paralelepipedo\n[3] Area do triangulo\n[4] Area do quadrado\n[5] Sair\n");
            scanf("%d", &n);
        } while (n <= 0 && n > 5);

        if (n == 1 || n == 2) scanf("%lf %lf %lf", &x, &y, &z);
        else if (n == 3 || n == 4) scanf("%lf %lf", &x, &y);
        system("cls");
        switch (n)
        {
        case 1:
            printf("Diagonal = %.2lf\n\n", diagonal_para(x, y, z));
            break;
        case 2:
            printf("Area = %.2lf\n\n", area_para(x, y, z));
            break;
        case 3:
            printf("Area = %.2lf\n\n", area_tri(x, y));
            break;
        case 4:
            printf("Area = %.2lf\n\n", area_quad(x, y));
            break;
        }
    } while (n != 5);
    
    return 0;    
}