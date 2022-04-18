# include <stdio.h> 
#include<stdlib.h>
typedef struct Root
{
    int data;struct Root *left,*right;
}root;
void inputElements(int arr[],int size);
void createTree(int data,root **root);
void preorder(root *Root);
int searchElement(int data,root *Root);
int main() {
    root *Root=NULL;
    int size;
    printf("enter the size of array: ");
    scanf("%d",&size);
    int array[size];
    inputElements(array,size);
    for(int i=0;i<size;i++)
    {
        createTree(array[i],&Root);
    }printf("tree successful\n");
    preorder(Root);
    int parent_data;
    printf("%d\n",searchElement(200,Root));

    return 0 ;
}
void inputElements(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("enter the %d element: ",(i+1));
        scanf("%d",&arr[i]);
    }
}
void createTree(int data,root **Root)
{
    root *curr=NULL;root *temp=*Root;
    curr=(root *)malloc(sizeof(root));// creation of node
    curr->data=data;// set dsta as curr->data
    curr->left=NULL;
    curr->right=NULL;
    if(*Root==NULL){*Root=temp=curr;}// set first data  as root
    else{
     while(temp!=NULL)// till root!=null
       {
         if(data<temp->data)// if < (move to left)
         {
             if(temp->left==NULL){temp->left=curr;break;}// insert node
             else{
                temp=temp->left;// till left becomed null
            }
         }
         else 
         {
            if(temp->right==NULL){temp->right=curr;break;}
            else{
                temp=temp->right;
            }
            }  
        }
    }
    
}
void preorder(root *Root)
{
    if(Root==NULL){return;}
    else{
        printf("%d\n",Root->data);
        preorder(Root->left);
        preorder(Root->right);
    }
}
int searchElement(int data,root *Root)
{
    root *curr=Root;
    if(curr==NULL){return -1;}
    while(curr!=NULL)
    {
        if(data==curr->data){printf("found");return 1;}// return 1 if data === curr->data
        else if(data<curr->left->data){curr=curr->left;}// if data< left[data](move to left child)
        else{
            curr=curr->right;printf("here\n"); // else move to right child
        }
    }return -1;
}