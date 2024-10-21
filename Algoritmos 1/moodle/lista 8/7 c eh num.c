#include <stdio.h>
#include <ctype.h>

int num(char c) {
    if (isdigit(c)) return 1;
    return 0;
}

int main() {
    char n;
    scanf("%c", &n);
    printf("%d", num(n));
    return 0;    
}