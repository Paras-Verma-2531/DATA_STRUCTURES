# include <stdio.h> 
# include <stdlib.h> 
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
void makeNode(int data);
void add(int data);
void display();
void addAtBeg(int data);
void addAtLast(int data);
int length();
void addAtPos(int pos,int data);
Node *node,*head,*temp,*tail;
int main() {
   add(23);
   add(48);
   add(100);
   add(200);
   addAtPos(4,500);
   display();
    return 0 ;
}
void makeNode(int data)
{
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
}
void add(int data)
{
    makeNode(data);
    if(head==NULL){head=tail=node;}
    else
    {
        tail->next=node;
        node->prev=tail;
        tail=tail->next;
    }
}
void display()
{
   if(head==NULL){printf("list is empty");}
    else{
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void addAtBeg(int data)
{
    makeNode(data);
    if(head==NULL){head=tail=node;}
    else{
        head->prev=node;
        node->next=head;
        head=node;
    }
}
void addAtLast(int data)
{
    makeNode(data);
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else{
        tail->next=node;
        node->prev=tail;
        tail=node;
    }
}
int length()
{ int c=0;
    if(head==NULL){return c;}
    else{
        temp=head;
        while (temp->next!=NULL)
        {
           temp=temp->next;
           c=c+1;
        }
        return c+1;
    }
}
void addAtPos(int pos,int data)
{
    int len=length();
    if((len<pos)||(pos<1)){printf("invalid position\n");}
    else if(pos==1)
    {
        addAtBeg(data);
    }
    else if(pos==len)
    { 
        makeNode(data);
        tail->prev->next=node;// accessing tail.prev.next
        node->next=tail;// now making node.next as tail
        node->prev=tail->prev;// nodde.prev as tail.prev
        tail->prev=node;// tail.prev=node
    }
    else{
        makeNode(data);
        temp=head;
        int i=1;
        while (i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        node->next=temp->next;
        temp->next->prev=node;
        temp->next=node;
        node->prev=temp;  
    }
}