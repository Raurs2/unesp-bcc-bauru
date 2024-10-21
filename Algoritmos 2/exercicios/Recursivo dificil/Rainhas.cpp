#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <system.h>




#define TRUE 1
#define FALSE 0

int LR(int lin, int TAB[5][5]){
	
   int col = 0;
   int PB = FALSE;
   
   if (lin >= 5){
    
   return TRUE;
   
   }else{
   	
      while (col < 5 && !PB){
      	
           TAB[lin][col] = TRUE;
           
           if (NA(TAB,lin,col)){
		   
               PB = LR(TAB,lin + 1);
               
       }
       
           if (!PB){
           	
               TAB[lin][col] = FALSE;
               col = col + 1;
               
           }
      }
       return PB;
   }
}

int NA(int lin, int col, int TAB[5][5]){
	
   int aux;
   int aux2;
   int PL = TRUE;
   aux = lin - 1;
   
   while (aux >= 0 && PL){
   	
       PL = !TAB[aux][col];
       aux = aux - 1;
       
   }
   aux = lin - 1;
  aux2 = col + 1;
  
  while (aux >= 0 && aux2 < 5 && PL){
  		
  	   aux2 = aux2 + 1;
  	   aux = aux - 1;
       PL = !TAB[aux][aux2];
       
       
   }
   aux = lin - 1;
   aux2 = col - 1;
   
  while (aux >= 0 && aux2 >= 0 && PL){
  	
       aux = aux - 1;
       aux2 = aux2 - 1;
       PL = !TAB[aux][aux2];
       
  }
   return PL;
}

void MS(int TAB[5][5]){
	
    int aux;
	int aux2;
	int whi = TRUE;
    putchar('\n');
   
   for (aux = 0; aux < 5; aux = aux + 1){
   	
     for (aux2 = 0; aux2 < 5; aux2 = aux2 + 1){
     	
         if (TAB[aux][aux2]) printf(" Q");{
         }else{
		 
               if (whi){
               	
               	printf(" O");
               	
			   }else{
			   	
			   	printf(" *");
			   	
			   } 
              
      }
          whi = !whi;
          
      }
      
      whi = !whi;
      printf("\n\n\n");
      
  }
}


int main(void){
	
   int aux;
   int aux2;
   int TAB[5][5];
   
   for (aux = 0; aux < 5; aux ++){
   
   
       for (aux2 = 0; aux2 < 5; aux2 = aux2 + 1){
	   
	   
	   TAB[aux][aux2] = FALSE;
	   
   		}
   if (LR(TAB,0)){
   	
    MS(TAB);
   	Sleep(1000);
   	return 0;
   	
   }else{
   
    printf("Nao Ha solucao\n");
   	Sleep(2000);
   	
   return 0;

}
}
}
