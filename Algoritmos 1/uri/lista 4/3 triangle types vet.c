#include <stdio.h>
 
int main() {
 
    float a, b, c, aux;
	scanf("%f %f %f", &a, &b, &c);
	
	if(b > a)
	{
		aux = a;
		a = b;
		b = aux;
	}
	if(c > b)
	{
		aux = b;
		b = c;
		c = aux;
	}
	if(b > a)
	{
		aux = a;
		a = b;
		b = aux;
	}
	printf("%.1f, %.1f, %.1f", a, b, c);
	if(a >= b+c)
	{
		printf("NAO FORMA TRIANGULO\n");
	}
	else
	{
		if(a*a == b*b + c*c)
		{
			printf("TRIANGULO RETANGULO\n");
		}
		else if(a*a > b*b + c*c)
		{
			printf("TRIANGULO OBTUSANGULO\n");
}
		else if(a*a < b*b + c*c)
		{
			printf("TRIANGULO ACUTANGULO\n");
		}
		
		if(a == b && b == c)
		{
			printf("TRIANGULO EQUILATERO\n");
		}
		else
		{
			if((a == b && b != c) || (a == c && b != a) || (b == c && a != c))
			{
				printf("TRIANGULO ISOSCELES\n");
			}
		}
	}
 
    return 0;
}