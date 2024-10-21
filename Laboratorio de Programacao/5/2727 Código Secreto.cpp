#include <cstdio>
#include <cstring>

/*
    vi a qtd de espaco em branco e de pontos e dependendo da qtd alternei qual letra mostrar
*/

int main()
{
    int n;
    char cod[200];
    while (scanf("%d", &n) != EOF)
    {
        for (int j = 0; j < n; j++)
        {
            
            scanf(" %[^\n]", cod);
            
            int blank_space = 0;
            for (int i = 0; i < strlen(cod); i++)
            {
                if (cod[i] == ' ') blank_space++;
            }

            int dot = 0;
            for (int i = 0; i < strlen(cod); i++)
            {
                if (cod[i] == '.') dot++;
                if (cod[i] == ' ') break;
            }
            if (blank_space == 0)
            {
                if (dot == 1) printf("a\n");
                if (dot == 2) printf("b\n");
                if (dot == 3) printf("c\n");
            } else if (blank_space == 1)
            {
                if (dot == 1) printf("d\n");
                if (dot == 2) printf("e\n");
                if (dot == 3) printf("f\n");
            } else if (blank_space == 2)
            {
                if (dot == 1) printf("g\n");
                if (dot == 2) printf("h\n");
                if (dot == 3) printf("i\n");
            } else if (blank_space == 3)
            {
                if (dot == 1) printf("j\n");
                if (dot == 2) printf("k\n");
                if (dot == 3) printf("l\n");
            } else if (blank_space == 4)
            {
                if (dot == 1) printf("m\n");
                if (dot == 2) printf("n\n");
                if (dot == 3) printf("o\n");
            } else if (blank_space == 5)
            {
                if (dot == 1) printf("p\n");
                if (dot == 2) printf("q\n");
                if (dot == 3) printf("r\n");
            } else if (blank_space == 6)
            {
                if (dot == 1) printf("s\n");
                if (dot == 2) printf("t\n");
                if (dot == 3) printf("u\n");
            } else if (blank_space == 7)
            {
                if (dot == 1) printf("v\n");
                if (dot == 2) printf("w\n");
                if (dot == 3) printf("x\n");
            } else if (blank_space == 8)
            {
                if (dot == 1) printf("y\n");
                if (dot == 2) printf("z\n");
            }
        }
        
    }

    return 0;
}
