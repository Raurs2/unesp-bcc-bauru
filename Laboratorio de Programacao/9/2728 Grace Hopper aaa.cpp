#include <stdio.h>
 
int main() {
 
    int i, j, f = 0;
    char c[300];
    char *p;
    while(scanf("%s", &c) != EOF)
    {
        p = strtok(c, "-");
        for(i = 0; i<5; i++)
        {
            f = 0;
            switch(i)
            {
                case 0:
                    if(toupper(p[0])=='C' || toupper(p[strlen(p)-1])=='C')
                        f = 1;
                    break;
                case 1:
                    if(toupper(p[0])=='O' || toupper(p[strlen(p)-1])=='O')
                        f = 1;
                    break;
                case 2:
                    if(toupper(p[0])=='B' || toupper(p[strlen(p)-1])=='B')
                        f = 1;
                    break;
                case 3:
                    if(toupper(p[0])=='O' || toupper(p[strlen(p)-1])=='O')
                        f = 1;
                    break;
                case 4:
                    if(toupper(p[0])=='L' || toupper(p[strlen(p)-1])=='L')
                        f = 1;
                    break;
            }
            if(f == 0)
                break;
            p = strtok(NULL, "-");            
        }
        if(f == 0)
        {
            printf("BUG\n");
        }else
        {
            printf("GRACE HOPPER\n");
        }
    }
    
    
    return 0;
}