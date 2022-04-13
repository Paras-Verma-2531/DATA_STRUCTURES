# include <stdio.h> 
#include<stdlib.h>
typedef struct Root
{
    int data;
    struct Root *left,*right;
}Root;
typedef struct Queue
{
    Root *Rnode;
    struct Queue *next;
}queue;
queue *node,*rear,*front;
Root *createTree();
void preorder(Root *root);
void postorder(Root *root);
void inorder(Root *root);
void createQueue(Root *root);
void enqueue(Root *root);
Root *dequeue(queue **front);
void levelorder(Root *root);
int main() {
    front=rear=NULL;
   Root *root=NULL;
   root=createTree(); 
   printf("preorder is :\n");
   preorder(root);
    printf("\nthe postorder is : ");
    postorder(root);
    printf("\nthe inorder is : ");
    inorder(root);
   printf("\nlevel order is:\n");
   levelorder(root);
    return 0;
}
Root *createTree()
{ Root *node=NULL;
    int data,choice;
    node=(Root *)malloc(sizeof(Root));
    printf("enter the data ('-1' for exit): ");
    scanf("%d",&data);
    if(data==-1){return NULL;}
    node->data=data;
    printf("enter the left child of %d :\n ",data);// enter left child data
    node->left=createTree();// recursive call for child left 
    printf("enter the right child of %d :\n",data);
    node->right=createTree();// recursive call for right left 
    return node;
}
void preorder(Root *root)
{
    if(root==NULL){return;}
    else{
        printf("%d\n",root->data); // print data
        preorder(root->left);// move to root's left
        preorder(root->right);// move to root's left
    }
}
void createQueue(Root *root)
{
  node=(queue *)malloc(sizeof(queue));
  node->Rnode=root;// stores the node 
  node->next=NULL;
}
void enqueue(Root *root)
{
    createQueue(root);
  if(front==NULL)
  {
      front=node;
  }else{
      rear->next=node;// add node to one's next
  }rear=node;
  //printf("the data is :%d\n",node->Rnode->data);
}
Root *dequeue(queue **front)
{
    Root *temp=NULL;
    if(*front!=NULL)
    {
    temp=(*front)->Rnode;
    *front=(*front)->next;
    }return temp;
}
void levelorder(Root *root)
{
    Root *temp=root;// stores root in temp
    while(temp)
    {
        printf("%d\n",temp->data);//print data
        if(temp->left){enqueue(temp->left);}// if left child exists enqueue the left child
        if(temp->right){enqueue(temp->right);}// if right child exists enqueue the right child
        temp=dequeue(&front);// dequeue the top element
    }
}
void postorder(Root *root)
{
    if(root==NULL){return;}
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}
void inorder(Root *root)
{
    if(root==NULL){return;}
    else{
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
