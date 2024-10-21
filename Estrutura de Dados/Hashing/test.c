#include <stdio.h>
#include <math.h>

#define max 100

int enlacamento_deslocado(int key, int table_digits)
{
    int key_digits = (int)floor(log10(abs(key))) + 1;
    while (key_digits % table_digits != 0)
    {
        key *= 10;
        key_digits++;
    }

    int i;
    int div = 1;
    for ( i = 0; i < table_digits; i++)
    {
        div *= 10;
    }
    
    int key_temp = key;
    int key_index = 0;

    for ( i = 0; i < key_digits/table_digits; i++)
    {
        key_index += key_temp % div;
        key_temp /= div; 
    }
    key_index += key_temp % div;
    return key_index;
}

int main()
{
    printf("index = %d\n", enlacamento_deslocado(123450, 2));
    return 0;
}
