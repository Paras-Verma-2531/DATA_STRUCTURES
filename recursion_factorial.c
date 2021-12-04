# include <stdio.h>
int factorial(int n)
{
    if(n==1||n==0)
    return 1;
    else{
        return n*factorial(n-1);
    }
}
int main() {
    int fact=factorial(5);
    printf("the factorial of %d is %d\n",5,fact);
 return 0 ;
}