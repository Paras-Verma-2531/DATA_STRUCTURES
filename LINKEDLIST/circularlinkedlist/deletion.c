# include <stdio.h> 
#include<stdlib.h>
typedef struct Node
{
    int data;struct Node *next;
}Node;
Node *head,*temp,*node,*tail;
void add(int data);
void display();
void makenode(int data);
void delete_from_pos(int pos);
void delete_from_beg();
void delete_from_last();
int length();
int main() {
    add(100);
    add(200);
    add(300);
    add(400);
    //delete_from_beg();
    //delete_from_last();
    delete_from_pos(3);
    display();
   return 0 ;
}
void makenode(int data)
{
node=(Node *)malloc(sizeof(Node));
node->data=data;
node->next=NULL;
}
void add(int data)
{
    makenode(data);
    if(head==NULL){head=tail=node;}
    else{
        
        tail->next=node;
        tail=node;
    }
    tail->next=head;// circular linking (linking to the head...)
}
void display()
{
    if(head==NULL){printf("list is empty\n");}
    else{
        temp=head;
        while(temp->next!=head) // since the last node also contains the address of head therefore we will  exit when temp == head
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void delete_from_beg()
{
    if(head==NULL){printf("list is empty\n");}
    else if(head->next==head)
    {
        head=NULL;
        free(head);
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
    }tail->next=head;
}
void delete_from_last()
{
    if(head==NULL){printf("list is empty\n");}
    else if(head->next==head)
    {
        head=NULL;
        free(head);
    }
    else{
        temp=head;
        while (temp->next->next!=head)
        {
            temp=temp->next;
        }
        free(tail);
        tail=temp;
        tail->next=head;
        //free(temp);
    }
}
void delete_from_pos(int pos)
{
    int i=1;
    if(pos<0||pos>length()){printf("invalid index!!\n");}
    if(head==NULL){printf("list is empty\n");}
    else if(pos==length()){delete_from_last();}
    else if(pos==1){delete_from_beg();}
    else{
        temp=head;
        while(i<pos-1)
        {
           temp=temp->next;
           i++;
        }
        temp->next=temp->next->next;
    }
}
int length()
{
    int c=0;
    if(head==NULL){return c;}
    else{
        temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
            c=c+1;
        }return c+1;
        
    }
}