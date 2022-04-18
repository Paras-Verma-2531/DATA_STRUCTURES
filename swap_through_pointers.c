# include <stdio.h>
void swap(int *a,int *b,int d,int c);
int main() {
    int a=23;
    int b=45;
    swap(&a,&b,a,b);
    
 return 0 ;
}
void swap(int *a,int *b,int d,int c)
{
    int t=0;
    t=*a;
    *a=*b;
    *b=t;
    printf(" the values before swaping are : a=%d and b=%d and after swapping are a=%d and b=%d\n",d,c,*a,*b);
}