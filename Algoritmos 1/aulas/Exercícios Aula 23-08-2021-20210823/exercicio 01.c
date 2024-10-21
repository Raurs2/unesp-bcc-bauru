int calc(int x){
  if(x < 0)
    return -1;
  if(x == 0)
    return 0;
  return 1;
}
//---------------------------------------------
int main(){
  int num;
  printf ("Digite um numero inteiro: ");
  scanf ("%d",&num);
  printf ("\n\n %d",calc(num));
  return 0;
}
