# include <stdio.h> 
#include<stdlib.h>
typedef struct Poly
{
    int coeff,pow;
    struct Poly *next;
}poly;
void create_poly(poly **head);
void display_poly(poly *head);
void add_poly(poly *pol1,poly *pol2,poly **poly3);
int main() {
    poly *pol1,*pol2,*pol3;
    pol1=pol2=pol3=NULL;
    printf("enter the first polynomial : \n");
    create_poly(&pol1);
    display_poly(pol1);
    printf("\nenter the second polynomial : \n");
    create_poly(&pol2);
    display_poly(pol2);
    //pol3=(poly *)malloc(sizeof(poly));
    add_poly(pol1,pol2,&pol3);
//     printf("the first polynomial is : ");
//   
//    printf("the second polynomial is : ");
//     display_poly(pol2);
    printf("the result is :\n");
    display_poly(pol3);
    return 0 ;
}
void create_poly(poly **head)
{
    poly *temp=*head,*new;int coff,pow; int choice;
    do
    {
        printf("enter the coefficient: ");
        scanf("%d",&coff);
        printf("enter the power: ");
        scanf("%d",&pow);
        new=(poly *)malloc(sizeof(poly));
        new->coeff=coff;
        new->pow=pow;
        new->next=NULL;
        if(temp==NULL)
        {
          *head=new;

        }  else{
            temp->next=new;
        } temp=new;
        printf("enter '1' to continue or '0' to exit\n");
        scanf("%d",&choice);
        
    }while(choice==1);
}
void display_poly(poly *head)
{
    poly *temp=head;
    while (temp->next!=NULL) {
        printf("%dx^%d",temp->coeff,temp->pow); // displays the coefficient and power of node
        temp = temp->next; // points to it's next
        if (temp->coeff>= 0) {
            //if (temp->next!= NULL) // for adding " + " operator
                printf(" + ");
        }
    }printf("%dx^%d",temp->coeff,temp->pow);
}
 void add_poly(poly *pol1,poly *pol2,poly **poly3)
{
    poly *pol3,*ptr=*poly3;
    while(pol1&& pol2)
   {
        pol3=(poly *)malloc(sizeof(poly));
       pol3->next=NULL;
       
       if(pol1->pow > pol2->pow)
       {
           pol3->pow=pol1->pow;
           pol3->coeff=pol1->coeff;
           pol1=pol1->next;
           
       }
        else if(pol2->pow > pol1->pow)
       {
           pol3->pow=pol2->pow;
           pol3->coeff=pol2->coeff;
           pol2=pol2->next;
           
       }
       else{
           pol3->coeff=pol1->coeff+pol2->coeff;
           pol3->pow=pol1->pow;
           pol1=pol1->next;
           pol2=pol2->next;
           
       }
      if(*poly3==NULL)
      {
         *poly3=pol3;
      }else{
          ptr->next=pol3;
        }ptr=pol3;
    }
    while(pol1|| pol2)
    {
        pol3=(poly *)malloc(sizeof(poly));
        
        pol3->next=NULL;
        if(pol1)
        {
            pol3->coeff=pol1->coeff;
            pol3->pow=pol1->pow;
            pol1=pol1->next;
        }
        if(pol2)
        {
            pol3->coeff=pol2->coeff;
            pol3->pow=pol2->pow;
            pol2=pol2->next;
        }
        ptr->next=pol3;
        ptr=pol3;
        
    }
}