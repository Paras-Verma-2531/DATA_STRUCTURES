# include <stdio.h> 
#include<stdlib.h>
typedef struct Node
{
    int data;struct Node *next;
}Node;
void createNode(int data);
void addAtBeg(int data);
void addAtPos(int data,int pos);
void addAtEnd(int data);
int  deleteFromBeg();
int deleteFromPos();
int deleteFromEnd();
void display();
void reverseIteration();
void reverseRecursive();
Node *node,*head,*temp;
int c=0;
int main() {
    addAtBeg(1);
    addAtEnd(2);
    addAtEnd(3);
    addAtEnd(4);
    addAtPos(100,2);
    display();
    int data=deleteFromBeg();
    data==-1?printf("list is empty\n"):printf("deleted data is :: %d\n",data);
    display();
    data=deleteFromEnd();
    data==-1?printf("list is empty\n"):printf("deleted data is :: %d\n",data);
    display();
    reverseIteration();
    printf("the list reversed through Iteration:\n");
    display();

    return 0 ;
}
void createNode(int data)
{
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    c+=1;
}
void addAtBeg(int data)
{
    createNode(data);
    if(head==NULL){head=temp=node;}
    else{
        node->next=head;
        head=node;
    }
}
void addAtEnd(int data)
{
    createNode(data);
    if(head==NULL){head=node;}
    else{
        temp->next=node;
    }temp=node;
}
void addAtPos(int data,int pos)
{ int count=1;
    if(pos>c || pos<=0){printf("invalid position\n");}
    if(pos==1){addAtBeg(data);}
    if(pos==c){addAtEnd(data);}
    else{
        temp=head;
        while(count<pos-1)
        {
            temp=temp->next;count+=1;
        }createNode(data);
        node->next=temp->next;
        temp->next=node;
    }
}
void display()
{
    temp=head;
    if(!temp){printf("list is empty\n");return;}
    printf("the list is : ");
    while(temp->next!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }printf("%d\n",temp->data);
}
int deleteFromBeg()
{  int data=-1;
    if(head)
    {
       data=head->data;
       if(head->next==NULL){head=NULL;}
       else{head=head->next;}
    }return data;
}
int deleteFromEnd()
{ int data=-1;
    if(head)
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }data=temp->next->data;
        temp->next=NULL;
    }return data;
}
void reverseIteration()
{
    Node *current,*prev,*next;
    prev=NULL;
    current=next=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }head=prev;
}