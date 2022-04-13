# include <stdio.h> 
# include <stdlib.h> 
typedef struct Node
{
    int data;
    struct Node *left,*right;
}Node;
Node *createNode(int data);
int searchElement(int data,Node *root);
int main() {
    // creation of static Binary Search Tree
    Node *root=NULL;
    root=createNode(38);
    root->left=createNode(14);
    root->right=createNode(56);
    root->left->left=createNode(8);
    root->left->right=createNode(23);
    root->left->right->left=createNode(18);
    root->right->left=createNode(45);
    root->right->right=createNode(82);
    root->right->right->left=createNode(70);
    printf("%d\n",searchElement(200,root));
    return 0 ;
}
Node *createNode(int data)
{
    Node *newnode;
    newnode= (Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int searchElement(int data,Node *root)
{
    Node *curr=root;
    if(curr==NULL){return -1;}
    while(curr!=NULL)
    {
        if(data==curr->data){return 1;}// return 1 if data === curr->data
        else if(data<curr->left->data){curr=curr->left;}// if data< left[data](move to left child)
        else{
            curr=curr->right; // else move to right child
        }
    }return -1;
}