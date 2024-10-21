#include <stdio.h>

int main(){
    int n, x, y;
    char entrada[3];

    gets(entrada);
    scanf("%d", &n);

    x = entrada[0]; y = entrada[2];

    if (n%2){
        if (n % 4 == 1){
            switch (x){
                case 60:
                    if(y == 94){
                        printf("cw\n");
                    } else{
                        printf("ccw\n");
                    }
                    break;
                case 62:
                    if(y == 118){
                        printf("cw\n");
                    } else{
                        printf("ccw\n");
                    }
                    break;
                case 94:
                    if(y == 62){
                        printf("cw\n");
                    } else{
                        printf("ccw\n");
                    }
                    break;
                case 118:
                    if(y == 60){
                        printf("cw\n");
                    } else{
                        printf("ccw\n");
                    }
                    break;
            }
        } else{
            switch (x){
                case 60:
                    if(y == 94){
                        printf("ccw\n");
                    } else{
                        printf("cw\n");
                    }
                    break;
                case 62:
                    if(y == 118){
                        printf("ccw\n");
                    } else{
                        printf("cw\n");
                    }
                    break;
                case 94:
                    if(y == 62){
                        printf("ccw\n");
                    } else{
                        printf("cw\n");
                    }
                    break;
                case 118:
                    if(y == 60){
                        printf("ccw\n");
                    } else{
                        printf("cw\n");
                    }
                    break;
            }
        }       
    } else{
        printf("undefined\n");
    }

    return 0;
}