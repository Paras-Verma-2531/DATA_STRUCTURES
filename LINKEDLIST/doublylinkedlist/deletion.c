
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
void makenode(int data);
void add(int data);
void display();
void delete_from_beg();
void delete_from_end();
void delete_from_pos(int n);
int length();
Node *head,*tail,*temp,*node;
int main()
{
    add(23);
    add(45);
    //add(100);
    add(200);
    add(78);
    //delete_from_beg();
    //delete_from_end();
   delete_from_pos(2);
    display();
   return 0;
}
void makenode(int data)
{
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
}
void add(int data)
{
    makenode(data);
    if(head==NULL){head=tail=node;}
    else
    {
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void delete_from_beg()
{
    if(head==NULL){printf("list is empty");}
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void delete_from_end()
{
    if(head==NULL){printf("list is empty");}
    else{
        temp=tail;
       tail=tail->prev;
       tail->next=NULL;
        free(temp);
    }
}
int length()
{
    int c=0;
    if(head==NULL){return c;}
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            c+=1;
        }return c+1;
    }
}
void delete_from_pos(int pos)
{
    if(pos>0&&pos==1){delete_from_beg();}
    else if(pos>0&&pos==length()){delete_from_end();}
    else {
        int i=1;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        Node *temp2;
        temp2=temp->next; // address of the node that is to be deleted ( from this we can access it's next and prev)
        temp->next=temp2->next;
        temp2->next->prev=temp;
        free(temp2);
        /* or i<pos
        
            temp=temp->next;
            i++;
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            */

    }
}