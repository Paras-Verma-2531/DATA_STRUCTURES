#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *next;
    int data;
} Node;
Node *node,*temp;
void makeNode(int data);
void addAtBeg(Node **head, int data);
void addAtEnd(Node **head, int data);
void addAtPos(Node **head, int pos, int data);
int deleteFromBeg(Node **head);
int deleteFromEnd(Node **head);
int deleteFromPos(Node **head,int pos);
void display(Node *head);
int length(Node *head);
int main()
{
    Node *head=NULL;
    int choice, data, pos,deleted_data;
    while (1)
    {
        printf("'1' to insert data at beginning\n '2' to add at end\n '3' to add at any position\n '4' to delete data from beginning \n'5' to delete from end\n '6' to delete from specific position\n '7' to display length of list\n '8' to display list\n '9' to exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the data to be inserted: ");
            scanf("%d", &data);
            addAtBeg(&head, data);
            break;
        case 2:
            printf("enter the data to be inserted: ");
            scanf("%d", &data);
            addAtEnd(&head,data);
            break;
        case 3:
            printf("enter the position where data is to inserted: ");
            scanf("%d",&pos);
            printf("enter the data to be inserted: ");
            scanf("%d",&data);
            addAtPos(&head,pos,data);
            break;
        case 4:
            deleted_data=deleteFromBeg(&head);
            (deleted_data==0)?printf(" "):printf("the deleted data is : %d\n",deleted_data);
            break;
        case 5:
            deleted_data=deleteFromEnd(&head);
            (deleted_data==0)?printf(" "):printf("the deleted data is : %d\n",deleted_data);
            break;
        case 6:
            printf("enter the position whose data you want to delete: ");
            scanf("%d",&pos);
           deleted_data=deleteFromPos(&head,pos);
           (deleted_data==0)?printf(" "):printf("the deleted data is : %d\n",deleted_data);
            break;
        case 7:
          printf("the length of list is : %d\n",length(head));
            break;            
        case 8:
            display(head);
          break;    
        case 9:
            exit(0);
        }
        printf("    **************     \n");
    }
    return 0;
}
void makeNode(int data)
{
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}
void addAtBeg(Node **head, int data)
{
    makeNode(data);
    if (*head == NULL){(*head)=node;}
    else
    {
        node->next = (*head);
        (*head) = node;
    }
}
void addAtEnd(Node **head,int data)
{
    makeNode(data);
    if(*head==NULL){(*head)=node;}
    else{
           temp=*head;
           while(temp->next!=NULL)
           {
               temp=temp->next;
           }temp->next=node;
    }
}
void display(Node *head)
{
    if (head == NULL){printf("list is empty\n");}// if head is null print list is empty
    else
    {
     printf("the list is :\n");
        temp = head;
        while (temp != NULL)//traverse till last node
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}
int length(Node *head)
{ 
    int c=0;
    if(head!=NULL)
    {
        temp=head;
        while(temp!=NULL)
        {
            //traverse till temp!=null and increase the value of c by 1
            temp=temp->next;
            c+=1; // shows the length
        }
    }return c;
}
void addAtPos(Node **head,int pos,int data)
{ 
   if(pos<1||pos>length(*head)){printf("invalid position!!\n");}
   else if((*head)==NULL||pos==1){addAtBeg(head,data);}
   else{
       makeNode(data);
       int i=1;temp=(*head);
       while(i<pos-1) // traverse till position -1
       {
           temp=temp->next;
           i++;
       }node->next=temp->next; // link new node to temp-next
       temp->next=node;// now link temp->next to node
   }
}
int deleteFromBeg(Node **head)
{
    int data;
    if((*head)==NULL){printf("list is empty!!\n");return 0;}
    else
    {
        temp=*head;
        *head=(*head)->next; // change the head to head->next(2nd element)
        data=temp->data;
        free(temp); // free the memory of deleted node
        return data;
    }
}
int deleteFromEnd(Node **head)
{
    int data;
    if((*head)==NULL){printf("list is empty!!\n");return 0;}
    else if((*head)->next==NULL){  data=(*head)->data; *head=NULL;return data;}
    else
    {
        temp=*head;
        while(temp->next->next!=NULL) // traverse till second last node
        {
            temp=temp->next;
        }
        data=temp->next->data;
        temp->next=NULL; // make the node null
        return data; // returns data
    }
}
int deleteFromPos(Node **head,int pos) // delete data from given position and thus returns the deleted data
{
    int data;
    if(pos<1||pos>length(*head)){printf("invalid position!!\n");return 0;}
   else if((*head)==NULL||pos==1){data=deleteFromBeg(head);return data;} // if position is head i,e 1 make call to deleteFromBeg;
   else if(pos==length(*head)){data=deleteFromEnd(head);return data;}// similarly make call to deleteFromEnd();
   else{
       int i=1;temp=*head;
       while(i<pos-1)
       {
           temp=temp->next;i++;
       }data=temp->next->data; // stores the deleted data
       temp->next=temp->next->next; // removing the reference of node at given pos
       return data;
   }
}
