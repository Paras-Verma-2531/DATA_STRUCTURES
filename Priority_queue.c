# include <stdio.h> 
# include <stdlib.h> 
typedef struct Node
{
    int data;int priority;
    struct Node *next;
}Node;
Node *node,*head,*temp;
void createNode(int priority,int data);// function prototype
void eneque(int priority,int data);// enqueue function
int dequeue(int *deleted_data);
void display();
int main() {
    int deleted_data,choice,data,priority;
    printf("*****   MAKE SURE TO NOT ENTER THE DATA AS '-1' AS IT STANDS FOR EMPTY QUEUE AND PRIORITY SHOULD BE IN + DIGIT*****\n");
    while(1)
    {
        printf(" '1' for enqueue\n '2' for dequeue\n '3' for display\n '4' for exit!!\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
         printf("enter the priority of the node: ");
         scanf("%d",&priority);// input the priority
         printf("enter the data : ");
         scanf("%d",&data); // input data
         eneque(priority,data);
         break;
        case 2:
         dequeue(&deleted_data);
         (deleted_data==-1)?printf("the queue is empty \n"): printf("the deleted data is : %d\n",deleted_data);
         break;
        case 3:
         printf("the queue is : ");
         display();
         break;
        case 4:
         exit(0);
         break;
        default:
         printf("enter the valid choice!!(1-4)\n");
         break;
        }
        printf("    ******************    \n");
    }
    return 0 ;
}

void createNode(int priority,int data)
{
 node=(Node *)malloc(sizeof(Node));
 node->priority=priority;node->data=data;// sets te priority and data to the node
 node->next=NULL;// set the next as null
}
void eneque(int priority,int data)
{
    createNode(priority,data);
    if(head==NULL){head=temp=node;}
    else if(node->priority<head->priority){node->next=head;head=temp=node;}
    // if priority of the node is less than the head node then insert at the beginning
    else{
        Node *temp2=head;// temporary node for head 
        while(temp2!=NULL){// traversing till the last node
            if(node->priority>temp2->priority)
           {  //temp=temp2;
               if(temp2->next==NULL){// if this is the last node insert the node at it's next
                   temp2->next=node;
                   break;
                }else{
                   temp2=temp2->next;// else move to next node
               }
           }
            else{
                if(node->priority==temp2->priority)
                {
                    node->next=temp2->next;temp2->next=node;break;// linking the new node
                }else{
                    temp2=temp2->next; // move to next node
                }
            }
        }
    }
}
void display()
{
    if(head==NULL){printf("queue is empty!!\n");}
    else{
        temp=head;
        while(temp->next!=NULL)// traverse till last node
        {
            printf("%d-->",temp->data);
            temp=temp->next; // move to the next node
        }printf("%d\n",temp->data);// print data of last node
    }
}
int dequeue(int *deleted_data)
{
    if(head!=NULL)
    {
        *deleted_data=head->data; // pass by reference for updating deleted_data
        head=head->next;
    }else{
        *deleted_data=-1; // if null set deleted_data= -1;
    }
}