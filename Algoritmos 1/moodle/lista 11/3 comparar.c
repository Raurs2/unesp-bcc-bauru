#include <stdio.h>
#include <string.h>
int main () {
    char str1[] = "mno", str2[] = "m\no";   
    char str3[] = "MNOP", str4[] = "MN0P"; 
    char str5[] = "MN\0P", str6[] = "MN0P"; 
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str3, str4));
    printf("%d\n", strcmp(str5, str6));
}