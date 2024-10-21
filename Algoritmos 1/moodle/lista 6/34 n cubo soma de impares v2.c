#include <stdio.h> 
 
main(){ 
 int n, m, i, j = 0; 
  
 scanf("%d", &n); 
 
 for(i = n; (i*n) != n*n*n; i++); 
  
 printf("O valor de de %d ao cubo eh de: %d\nEsse valor pode ser atingido somando: ", n, n*n*n, i); 
  
 if(i%2){ 
  m = n/2; 
   
  for(j = 0; j < m; j++){ 
   printf("%d ", i-(2*(m-j))); 
  } 
   
  for(j = 0; j <= m; j++){ 
   printf("%d ", i+(2*j)); 
  } 
   
  printf("\n"); 
 } else { 
  m = n/2; 
   
  for(j = 1; j <= m; j++){ 
   printf("%d ", i-1-(2*(m-j))); 
  } 
   
  for(j = 0; j < m; j++){ 
   printf("%d ", i+1+(2*j)); 
  } 
   
  printf("\n"); 
 } 
   
 return 0; 
}