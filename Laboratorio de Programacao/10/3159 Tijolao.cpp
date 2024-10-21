#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
    
*/

int pegaVezes(int c) {
    int vezes;
    switch (c) {
        case '1':
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w':
        case ' ':
            vezes = 1;
            break;
        case '0':
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x':
            vezes = 2;
            break;
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '8':
        case 's':
        case 'z':
            vezes = 4;
            break;
        case '7':
        case '9':
            vezes = 5;
            break;
        default:
            vezes = 3;
    }
    return vezes;
}

int pegaTecla (int c) {
    int tecla;
    switch (c) {
        case '1':
            tecla = 1;
            break;
        case '2':
        case 'a':
        case 'b':
        case 'c':
            tecla = 2;
            break;
        case '3':
        case 'd':
        case 'e':
        case 'f':
            tecla = 3;
            break;
        case '4':
        case 'g':
        case 'h':
        case 'i':
            tecla = 4;
            break;
        case '5':
        case 'j':
        case 'k':
        case 'l':
            tecla = 5;
            break;
        case '6':
        case 'm':
        case 'n':
        case 'o':
            tecla = 6;
            break;
        case '7':
        case 'p':
        case 'q':
        case 'r':
        case 's':
            tecla = 7;
            break;
        case '8':
        case 't':
        case 'u':
        case 'v':
            tecla = 8;
            break;
        case '9':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            tecla = 9;
            break;
        default:
            tecla = 0;
    }
    return tecla;
}

int main() {
    
    int n, i, j, tecla, teclaAnterior, maiuscula, vezes;
    char frase[150], codigo;
    scanf("%d", &n);
    getchar();
    
    while (n--) {
        
        fgets(frase, 150, stdin);
        for (i = 0; i < strlen(frase); i++) {
            
            codigo = frase[i];
            if (codigo == '\n')
                continue;

            maiuscula = (codigo <= 90 && codigo >= 65? 1 : 0);
                
            tecla = pegaTecla(tolower(codigo));
            if (i > 0)
                teclaAnterior = pegaTecla(tolower(frase[i-1]));
            
            if (maiuscula) {
                printf("#");
                codigo += 32;
            }
            else if (tecla == teclaAnterior && !maiuscula && i)
                printf("*");

            vezes = pegaVezes(codigo);
            for (j = 0; j < vezes; j++)
                printf("%i", tecla);
        }
        
        printf("\n");
    }
    return 0;
}