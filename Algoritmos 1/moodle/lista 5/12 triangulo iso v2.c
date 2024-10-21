#include <stdio.h> 

main(){ 
int contL, contE, contV = 1, contT, cons = 5; 
for (contL = 0; contL < cons; contL++){ 
for(contT = 0; contT < (cons - contL); contT++){ 
printf(" "); 
} 
for(contE = 1; contE <= contV; contE++){ 
printf(" * "); 
} 
contV += 2; 
printf("\n"); 
} 
return 0; 
}