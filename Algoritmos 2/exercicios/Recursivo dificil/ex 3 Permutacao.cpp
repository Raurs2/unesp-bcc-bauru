#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <system.h>


void per(int start, int end, char str[]){
	
	int a = 0;
	
	if(start == end){
		
		for(a=0; a<=end; a++){
			
			printf("%c \n\n", str[a]);
		}
		
		
	}else{
		
		for(a=start; a<=end; a++){
			
			per(str, start + 1, end);
			cl(str, start, a);
			
		}
	}
}

int cl(int b, int a, char str[]){
	
	char aux;
	
	str[b] = str[a];
	aux = str[b];
	str[a] = aux;
	
	return cl;	
}

int main (){
	
	char let[100];
	int size;
	
	printf("Insira a quantidade de letras: ");
	
	gets(let);
	
	size = strlen(let);
	
	Sleep(1000);
	system("cls");
	
	printf("Permutacoes: ");
	per(let, 0, size - 1);
	
	return 0;
	
}
