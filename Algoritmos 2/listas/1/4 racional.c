#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} racional;

void troca(int *n1, int *n2) {
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int mdc(int n1, int n2) {
    do
    {
        int r = n1 % n2;
        n1 = n2;
        n2 = r;
    } while (n2 != 0);
    return n1;
}

int mmc(int a, int b) {
    return (a*b) / mdc(a, b);
}

void reduz(racional *razao, int c) {
    (*razao).a /= c;
    (*razao).b /= c;
}

void neg(racional *razao) {
    (*razao).a *= -1;
}

void soma(racional *r1, racional *r2, racional *r) {
    int c = mmc((*r1).b, (*r2).b);
    (*r).a = c / (*r1).b * (*r1).a + c / (*r2).b * (*r2).a;
    (*r).b = c;
}

void mult(racional *r1, racional *r2, racional *r) {
    (*r).a = (*r2).a * (*r1).a;
    (*r).b = (*r2).b * (*r1).b;
}

void divi(racional *r1, racional *r2, racional *r) {
    (*r).a = (*r2).b * (*r1).a;
    (*r).b = (*r2).a * (*r1).b;
}

int main()
{
    racional razao, razao2, r;
    scanf("%d %d", &razao.a, &razao.b);
    
    int c = mdc(razao.a, razao.b);
    reduz(&razao, c);
    printf("%d/%d\n", razao.a, razao.b);
    
    neg(&razao);
    printf("%d/%d\n", razao.a, razao.b);
    
    scanf("%d %d", &razao.a, &razao.b);
    scanf("%d %d", &razao2.a, &razao2.b);

    soma(&razao, &razao2, &r);
    c = mdc(r.a, r.b);
    reduz(&r, c);
    printf("%d/%d + %d/%d = %d/%d\n", razao.a, razao.b, razao2.a, razao2.b, r.a, r.b);

    mult(&razao, &razao2, &r);
    c = mdc(r.a, r.b);
    reduz(&r, c);
    printf("%d/%d * %d/%d = %d/%d\n", razao.a, razao.b, razao2.a, razao2.b, r.a, r.b);

    divi(&razao, &razao2, &r);
    c = mdc(r.a, r.b);
    reduz(&r, c);
    printf("%d/%d / %d/%d = %d/%d\n", razao.a, razao.b, razao2.a, razao2.b, r.a, r.b);
    
    return 0;
}
