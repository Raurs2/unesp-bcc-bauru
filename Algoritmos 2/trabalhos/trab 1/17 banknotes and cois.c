#include <stdio.h>
#include <math.h>

int main() {
    int n100, n50, n20, n10, n5, n2, m1, m05, m025, m01, m005, m001;
    double v;
    scanf("%lf", &v);
    n100 = v / 100;
    v = fmod(v, 100);
    n50 = v/50;
    v = fmod(v, 50);
    n20 = v/20;
    v = fmod(v, 20);
    n10 = v/10;
    v = fmod(v, 10);
    n5 = v/5;
    v = fmod(v, 5);
    n2 = v/2;
    v = fmod(v, 2);
    m1 = v/1;
    v = fmod(v, 1);
    m05 = (int)(v/0.5);
    v = fmod(v, 0.5);
    m025 = (int)(v/0.25);
    v = fmod(v, 0.25);
    m01 = (int)(v/0.1);
    v = fmod(v, 0.1);
    m005 = (int)(v/0.05);
    v = fmod(v, 0.05);
    m001 = (int)(v/0.01);
    v = fmod(v, 0.01);
    printf("NOTAS:\n"); 
    printf("%d nota(s) de R$ 100.00\n",n100); 
    printf("%d nota(s) de R$ 50.00\n",n50); 
    printf("%d nota(s) de R$ 20.00\n",n20); 
    printf("%d nota(s) de R$ 10.00\n",n10); 
    printf("%d nota(s) de R$ 5.00\n",n5); 
    printf("%d nota(s) de R$ 2.00\n",n2); 
    
    printf("MOEDAS:\n"); 
    printf("%d moeda(s) de R$ 1.00\n",m1); 
    printf("%d moeda(s) de R$ 0.50\n",m05); 
    printf("%d moeda(s) de R$ 0.25\n",m025); 
    printf("%d moeda(s) de R$ 0.10\n",m01); 
    printf("%d moeda(s) de R$ 0.05\n",m005); 
    printf("%d moeda(s) de R$ 0.01\n",m001);
    return 0;
}