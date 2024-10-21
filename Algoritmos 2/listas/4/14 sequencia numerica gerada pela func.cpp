#include <cstdio>
#include <cstdlib>


int F (int n){
    if (n == 0)
    {
        printf(" 1 ");
        return 1;
    } else if (n == 1)
    {
        printf(" 2 ");
        return 2;
    } else
    {
        printf(" 2 * %d * %d *", n - 2, n - 1); 
        return 2*F(n-2)*F(n-1);
    }
    
}
int main(){
    int n = 5;
    printf(" = %d", F(n));
    return 0;
}    

//  2 * 3 * 4 * 2 * 1 * 2 * 2  2 * 0 * 1 * 1  2  2 * 2 * 3 * 2 * 0 * 1 * 1  2  2 * 1 * 2 * 2  2 * 0 * 1 * 1  2  = 4096