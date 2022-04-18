# include <stdio.h> 
# include<stdlib.h>
typedef struct Node
{
    int data;struct Node *next,*prev;
}Node;
Node *head,*tail,*node;
void add(int data);
void reverseRecursion(Node *head,Node *tail);
void swap(Node **head,Node **tail);
void createNode(int data);
void reverseIteration();
void display();
int main() {
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    display();
    reverseRecursion(head,tail);
    display();
    reverseIteration();
    display();
    return 0 ;
}
void createNode(int data)
{
    node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    node->prev=NULL;
}
void add(int data)
{
    createNode(data);
    if(head==NULL){head=node;}
    else{
        tail->next=node;
        node->prev=tail;
    }tail=node;
}
void display()
{
    Node *temp=head;
    while(temp->next!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }printf("%d\n",temp->data);
}
void swap(Node **head,Node **tail)
{
    int s=0;
    s=(*head)->data;
    (*head)->data=(*tail)->data;
    (*tail)->data=s;
}
void reverseRecursion(Node *head, Node *tail)
{
    if(head==tail){return;}
    swap(&head,&tail);//swap head and tail data
    reverseRecursion(head->next,tail->prev);//pass head->next;tail->prev
    //recursive call
}
void reverseIteration()
{
    if(head==NULL){printf("list is empty\n");}
    else if(head->next==NULL){return;}
    else{
        Node *current,*prevnode,*nextnode;
        current=head;prevnode=NULL;
        while(current!=NULL)
        {
            nextnode=current->next;
            current->prev=nextnode;
            current->next=prevnode;
            prevnode=current;
            current=nextnode;
        }tail=head;
        head=prevnode;
    }
}