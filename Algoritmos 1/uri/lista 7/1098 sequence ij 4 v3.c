#include <stdio.h> 
 
main(){ 
    double i, j, min = 1, max = 3; 

    for(i = 0, min =1, max =3; i <= 2; i += 0.2, min += 0.2, max += 0.2){ 
            for(j = min; j <= max; j++){ 
                if (i == 0 || i > 0.9 && i < 1.1 || i > 1.8){ 
                printf("I=%.lf J=%.lf\n", i, j); 
                } else { 
                printf("I=%.1lf J=%.1lf\n", i, j); 
                } 
            } 
    } 
    
    return 0; 
}