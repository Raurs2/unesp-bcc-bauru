#include<stdio.h>
#include<string.h>
int main() {
  char str1[50],str2[50],str3[50];
  strcpy (str1,"Sequencia de caracteres.");
  strcpy (str2,"SEQUENCIA de CARACTERES.");
  strcpy (str3,"Cadeia de caracteres diferente.");
  printf ("str1: %s\n",str1);
  printf ("str2: %s\n",str2);
  printf ("str3: %s\n\n",str3);
  printf ("str1 e str2: %d\n",stricmp(str1,str2));
  printf ("str1 e str3: %d\n",stricmp(str1,str3));
  printf ("str2 e str3: %d\n",stricmp(str2,str3));
  printf ("str3 e str1: %d\n",stricmp(str3,str1));
  printf ("str2 e str1: %d\n",stricmp(str2,str1));
}

