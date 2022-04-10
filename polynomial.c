# include <stdio.h> 
# include <stdlib.h> 
typedef struct Node
{
    int coff,exp;
    struct Node *next;
}Node;
void createPoly(Node **poly);
void display(Node *poly);
void addPoly(Node *poly1,Node *poly2,Node **poly3);
int main() {
    Node *pol1,*pol2,*pol3;
    pol1=pol2=pol3=NULL;
    printf("enter the first polynomial\n");
    createPoly(&pol1);
    printf("the first polynomial is : ");
    display(pol1);
    printf("\nenter the second polynomial\n");
    createPoly(&pol2);
    printf("\nthe second polynomial is : ");
    display(pol2);
    printf("\nthe sum of two polynomial is :");
    addPoly(pol1,pol2,&pol3);
    display(pol3);
    return 0 ;
}
void createPoly(Node **poly)
{Node *temp=*poly;
 Node *pol;int choice;
    do
    {
        pol=(Node *)malloc(sizeof(Node));
        printf("enter the coffecient: ");
        scanf("%d",&pol->coff);
        printf("enter the degree : ");
        scanf("%d",&pol->exp);
        pol->next=NULL;
        if(temp==NULL)
        {
            *poly=pol;
        }else{
               temp->next=pol;
        }temp=pol;
        printf("enter '0' to exit or '!0' to continue: ");
        scanf("%d",&choice);
    }while (choice);
}
void display(Node *poly)
{
    while(poly->next!=NULL)
    {
        printf("%dx^%d",poly->coff,poly->exp);
        poly=poly->next;
        if(poly->coff>0)
        {printf("+");}
    }printf("%dx^%d",poly->coff,poly->exp);
}
void addPoly(Node *poly1,Node *poly2,Node **poly3)
{
    Node *polyn=*poly3;Node *ptr;
    while(poly1&&poly2)
    { 
        ptr=(Node *)malloc(sizeof(Node));
        ptr->next=NULL;
        if(poly1->exp>poly2->exp)
        {
           ptr->coff=poly1->coff;
           ptr->exp=poly1->exp;
           poly1=poly1->next;
        }
        else if(poly2->exp>poly1->exp)
        {
            ptr->coff=poly2->coff;
           ptr->exp=poly2->exp;
           poly2=poly2->next;
        }
        else{
            ptr->coff=poly1->coff+poly2->coff;
           ptr->exp=poly1->exp;
           poly1=poly1->next;
           poly2=poly2->next;
        }
        if(*poly3==NULL)
        {
            *poly3=ptr;
        }else{
            polyn->next=ptr;
        }polyn=ptr;
        while(poly1 ||poly2)
        {
            ptr=(Node *)malloc(sizeof(Node));
            ptr->next=NULL;
            if(poly1)
            {
                ptr->coff=poly1->coff;
                ptr->exp=poly1->exp;
                poly1=poly1->next;
            }
            if(poly2)
            {
                ptr->coff=poly2->coff;
                ptr->exp=poly2->exp;
                poly2=poly2->next;
            }
            polyn->next=ptr;
            polyn=ptr;
        }

    }
}
