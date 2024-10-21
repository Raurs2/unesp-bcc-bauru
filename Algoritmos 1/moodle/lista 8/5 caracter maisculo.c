#include <stdio.h>
#include <ctype.h>
char toup(char c) {
    if (islower(c)) return toupper(c);
    else return c;
}
int main() {
    char c;
    scanf("%c", &c);
    printf("%c", toup(c));
    return 0;    
}