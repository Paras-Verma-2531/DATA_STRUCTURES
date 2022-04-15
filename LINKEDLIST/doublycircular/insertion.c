# include <stdio.h> 
# include <stdlib.h> 
typedef struct Node
{
    struct Node *next;struct Node *prev;
    int data;
}Node;
void add(int data);
void makenode(int data);
void display();
void insert_at_beg(int data);
void insert_at_end(int data);
int length();
void insert_after_a_pos(int pos,int data);
Node *head,*tail,*temp,*node;
int main() {
    add(1);
    add(2);
    add(3);
    add(4);
    // insert_at_beg(111);
    insert_at_end(222);
    insert_after_a_pos(3,222);
    display();
    //printf("%d",length());
    return 0 ;
}
void makenode(int data)
{
    node=(Node *)malloc(sizeof(Node));
    node->data=data;node->next=NULL;node->prev=NULL;
}
void add(int data)
{
    makenode(data);
    if(head==NULL){head=tail=node;}
    else{
        tail->next=node;
        node->prev=tail;// address of previous node;
        tail=node; // updating tail
        tail->next=head; // tail-> next will point to head;
    }head->prev=tail;
}
void display()
{
    if(head==NULL){printf("list is empty\n");}
    else{
        temp=head;
        while(temp->next!=head)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }printf("%d\n",temp->data);
    }
}
void insert_at_end(int data)
{
    makenode(data);
    if(head==NULL){head=tail=node;}
    else{
        tail->next=node;
        node->prev=tail;
        //node->next=head;
        tail=node;
    }head->prev=node;
    tail->next=head;
}
void insert_at_beg(int data)
{
    makenode(data);
    if(head==NULL){head=tail=node;}
    else{
        node->next=head;
        head->prev=node;
        head=node;
    }head->prev=node;//circular linking
    tail->next=head;// circular linking
}
int length()
{ int c=0;
    if(head==NULL){return c;}
    else{
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            c+=1;
        }return c+1;
    }
}
void insert_after_a_pos(int pos,int data)
{
    if(pos<1||pos>length()){printf("invalid position!!\n");}
    else if(pos==1){
        insert_at_beg(data);
    }
    else if(pos==length()){insert_at_end(data);}
    else{
        makenode(data);
        int i=1;
        temp=head;
        while(i<pos)// will reach till that position
        {
            temp=temp->next;
            i++;
        }node->next=temp->next; // node next will point to temp next
        temp->next->prev=node;// temp next prev will point to node
        node->prev=temp;// node prev will point to temp
        temp->next=node;// temp next will point to node
    }
}