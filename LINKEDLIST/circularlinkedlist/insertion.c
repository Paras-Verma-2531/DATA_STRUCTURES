# include <stdio.h> 
#include<stdlib.h>
typedef struct Node
{
    int data;struct Node *next;
}Node;
Node *head,*temp,*node,*tail;
void add(int data);
int length();
void makenode(int data);
void insert_at_beg(int data);
void insert_at_end(int data);
void insert_at_pos(int pos,int data);
void display();
int main() {
    add(23);
    add(45);
    add(56);
    add(78);
    insert_at_beg(100);
    insert_at_end(200);
    insert_at_pos(6,300);
    display();
    //printf("the length is %d",length());
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
void insert_at_beg(int data)
{
    makenode(data);
    if(head== NULL){head=tail=node;}
    else{
        node->next=head;
        head=node;
    }tail->next=head;
}
void insert_at_end(int data)
{
    makenode(data);
    if(head==NULL){head=tail=node;} // if list is empty make it as a first node;
    else{
        //else insert it at the tail's next and update the tail;
        tail->next=node;
        tail=node;
    }tail->next=head; // circular linking
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
void insert_at_pos(int pos,int data)
{
    if(pos<0||pos>length()){printf("insertion not possible!!\n");}
    else if(pos==1){insert_at_beg(data);}
    else 
    {
        int i=1;
        makenode(data);
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        node->next=temp->next;
        temp->next=node;
    }
}
