#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *node, *head;
void push(int data);
int pop();// function definition
int peek();
void makenode(int data);
void display();
int main()
{
    int data, choice,poped_element,top_element;
    while (1)
    {
        printf("'1' for push\n '2' for pop\n '3' for peek\n '4' for display\n '5' to exit\n");
        scanf("%d", &choice);
        switch (choice) // functions as per user choice
        {
        case 1:
            printf("enter the element that you want to push into stack: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            poped_element=pop();// returns the top most element and thus remove it from the  stack
            printf("the poped element is : %d\n",poped_element);
            break;
        case 3:
           top_element=peek();
           printf("the top of stack is : %d\n",top_element);
            break;
        case 4:
         display(); // call the display function
         break;
        case 5:
         exit(0);
        default:
         printf("invalid choice!!\n");
            break;
        }
        printf("         ****************          \n");
    }
    return 0;
}
void push(int data)
{
    makenode(data);
    if (head == NULL){head=node;}
    else
    {
        node->next = head; // add the element to the top of stack
        head = node;
    }
}
int pop()
{
    if (head == NULL){printf("stack is empty!!\n");}
   else
    {
        Node *temp = head;
        int data = head->data;
        head = head->next;
        free(temp);
        return data;// returns the top of stack and delete it from stack as well
    }
    return;
}
int peek()
{ if (head == NULL){printf("stack is empty!!\n");}
    else
    {
        return head->data; // returns the top of stack
    }
    return;
}
void makenode(int data)
{
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}
void display() // displays the content of stack
{
    if(head==NULL){printf("stack is empty!!\n");}
    else{
        Node *temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next; // traversing to the next element
        }
    }
}