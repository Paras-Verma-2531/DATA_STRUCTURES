# include <stdio.h>
# include <string.h>
void input(char *string);
char *display(char *string);
void push(char stack[],int size,int *top,char *string);
void reverse(char reverse_string[],int size,char stack[],int *top);
char pop(char stack[],int size,int *top);
int main() {
    int size;int top=-1;
    printf("enter the length of string : ");
    scanf("%d",&size);// ask the length of string from user
    char string[size];
    char stack[50];
    char *string_pt=string;// pointer referene of string
    char reverse_string[50];// reverse string array of length 50
    char *reverse__string=reverse_string;// pointer referene of reverse string
    input(string_pt);
    push(stack,strlen(string_pt),&top,string_pt);
    reverse(reverse_string,strlen(string_pt),stack,&top);
    printf("the original string is : %s\n",display(string_pt));
    printf("the reverse string is : %s\n",display(reverse__string));
    return 0 ;
}
void input(char *string)
{
   printf("enter the string: ");//ask the string from user
    fflush(stdin);
    gets(string);
}
char *display(char *string)
{
  return string; // returns the string pointer
}
void push(char stack[],int size,int *top,char *string)
{
   if(*top==size-1){printf("the stack is overflow\n");} // check for overflow condition
   else{
       for(int i=0;i<size;i++)
       {
       *top=*top+1; // top increased by 1
       stack[*top]=*(string+i); // stack array will contain data at stack[top]
       //stores character by character
    }
    }
}
char pop(char stack[],int size,int *top)
{char data='\0';
    if(*top==-1){printf("stack is underflow!!");}
    else{
        data=stack[*top];
        *top=*top-1;
    }return data;// returns the topmost element
}
void reverse(char reverse_string[],int size,char stack[],int *top)
{
    for(int i=0;i<size;i++)
    {
        reverse_string[i]=pop(stack,size,top);/*reverse_string array stores character in reverse order returned from 
        pop function*/
    }
}