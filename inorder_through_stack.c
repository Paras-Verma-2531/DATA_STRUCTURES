# include <stdio.h> 
#include<stdlib.h>
typedef struct Root
{
    int data;
    struct Root *left,*right;
}Root;
typedef struct Stack
{
   Root *Rnode;
   struct Stack *next;
}stack;
stack *node,*top;
void createStack(Root *root);
Root *createStaticTree();
int *isEmpty(stack *top);
Root *pop(stack **top);

void push(Root *root);
void inorder(Root *root);
int main() {
    Root *root=NULL;
    root=createStaticTree();
    printf("the inorder is :\n");
    inorder(root);
    return 0 ;
}
void createStack(Root *root)
{
    node=(stack *)malloc(sizeof(stack));
    node->Rnode=root;
    node->next=NULL;
}
Root *createStaticTree()
{int data;
    Root *node=NULL;
   node=(Root *)malloc(sizeof(Root));
   printf("enter '-1' to return: else any other data: ");
   scanf("%d",&data);
   if(data==-1){return NULL;}
   node->data=data;
   printf("enter the left child of %d:\n",data);
   node->left=createStaticTree();
   printf("enter the right child of %d:\n",data);
   node->right=createStaticTree();
   return node;
}
int *isEmpty(stack *top)
{
    return(top==NULL)?1:0;
}
Root *pop(stack **top)
{
    Root *val=NULL;
    if(*top!=NULL)
    {
        val=(*top)->Rnode;
        *top=(*top)->next;
    }return val;
}
void push(Root *root)
{
    createStack(root);
    if(top==NULL){}
    else{
        node->next=top;
    }top=node;
}
void inorder(Root *root)
{
    Root *temp=root;
    if(temp==NULL){printf("tree is empty\n");}
    else{
        Root *cur=root;
        while(!isEmpty(top)||cur!=NULL)
        {
            while(cur!=NULL)
            {
                push(cur);
                cur=cur->left;
            }
            cur=pop(&top);
            printf("%d\n",cur->data);
            cur=cur->right;
        }
    }
}