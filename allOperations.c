# include <stdio.h> 
# include <stdlib.h> 
typedef struct Node
{
    struct Node *next;int data;
}Node;
Node *top=NULL;Node *temp,*node;
void push(int data);
void pop();
void peek();
void display();
int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("   *********     \n");
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    return 0 ;
}
void push(int data)
{
 node=(Node *)malloc(sizeof(Node));
 node->next=top;
 node->data=data;
 top=node;
}
void pop()
{
    if(top==NULL){printf("stack is empty\n");}
    else{
        temp=top;
        printf("the poped element is : %d\n",top->data);
        top=top->next;
        free(temp);
    }
}
void peek()
{
    if(top==NULL){printf("stack is empty\n");}
    else{
        printf("the element to be poped out  is : %d\n",top->data);
    }
}
void display()
{
    if(top==NULL){printf("stack is empty\n");}
    else{
        temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}