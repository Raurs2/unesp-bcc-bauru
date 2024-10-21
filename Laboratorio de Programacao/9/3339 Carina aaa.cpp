#include<stdio.h>
#include<math.h>
int main(){
    int num, min, max, aux=0, j, i;
    scanf("%d", &num);

    for(i=0; i<num; i++){
        scanf("%d %d", &min, &max);
        for(j=0; j<max; j++){
            if(pow(j,2)>=min && pow(j,2)<=max)
            aux++;
            else if(pow(j,2)>=max)
            break;
        }
        printf("%d\n", aux);
        aux=0;
    }
    return 0;
}