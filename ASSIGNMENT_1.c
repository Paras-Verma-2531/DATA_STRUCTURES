# include <stdio.h>
# include <stdlib.h> 
typedef struct Node
{
    int key,data;
    struct Node *next;
}Node;
void add_data(int key,int data);
void inputElements(int size);
void sortList(int size);
void display();
void createNode(int data,int key);
void insert_update(int key,int value);
int search(int key);
int delete(int key);
int length();
int isKeyExists(int key);
Node *node,*tail,*head;
int main() {
    int size,key,deleted_data,data,choice;
    printf("enter the initial size of list : ");
    scanf("%d",&size);
    inputElements(size);
    sortList(size);
    while (1)
    {
        printf("'1' to insert/update the data\n'2' to search the desired key\n'3' to delete the data of particular key\n'4' to return the length\n'5' to check if key exists\n'6' to display the dictionary\n'7' to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            printf("   *************      \n");
          case 1:
          printf("enter the key and it's value : ");
          scanf("%d %d",&key,&data);
          insert_update(key,data);
          break;
        case 2:
         printf("enter the key to be searched: ");
         scanf("%d",&key);
         (search(key)!=-1)?printf("the value associated with %d key is %d\n",key,search(key)):printf("the key does not exists\n");
         break;
        case 3:
         printf("enter the key you want to delete : ");
         scanf("%d",&key);
         deleted_data=delete(key);
         (deleted_data==-1)?printf("the key %d does not exists in the dictionary\n",key):printf("the key %d with value %d is now deleted\n",key,deleted_data);
         break;
        case 4:
         printf("the length of the list is : %d\n",length());
         break;
        case 5:
         printf("enter the key to be searched: ");
         scanf("%d",&key);
         (isKeyExists(key)==1)?printf("the key %d exists in the dictionary\n",key):printf("the key %d does not exists\n",key);
         break;
         case 6:
         display();
         break;
         case 7:
         exit(0);
        default:
         printf("invalid choice !!\n");
         break;
        }
    printf("    **********     \n"); 
    }
    
    return 0 ;
}
void inputElements(int size)// input the initial elements(key,data)
{ int key,data;
    for(int i=0;i<size;i++)
    {
        printf("enter the key and value of %d element : ",(i+1));
        scanf("%d %d",&key,&data);// stores the key and value of n elements
        add_data(key,data);// add_data function call
    }
}
void createNode(int key,int data)
{
    node=(Node *)malloc(sizeof(Node));// creates new node
    node->key=key; // set the key of new node as key(given by user)
    node->data=data; // set the data of new node as data(given by user)
    node->next=NULL;
}
void sortList(int size)
{ int key,data;Node *i,*j;
 i=head;
 for(i=head;i!=NULL;i=i->next)
 {
    for(j=i->next;j!=NULL;j=j->next)
    {
     if(i->key> j->key)
     {
        key=i->key;data=i->data;
        i->key=j->key;i->data=j->data;//swapping of data and key
        j->key=key;j->data=data;
     }
    }
 }
}
void display()
{
   Node *temp=head;int i=0;
   while(temp!=NULL)
   {
     printf("the key and value of %d element is : %d ---> %d\n",(i+1),temp->key,temp->data);
     temp=temp->next;
     i++;
     // prints the  key and data of 'n' elements
   }
}
void add_data(int key,int data)
{Node *temp;int c=0;
    createNode(key,data);// function call
  temp=head;
  if(head==NULL){head=tail=node;}
 else{
     while(temp!=NULL)// traversing through the list to check duplicate element
       {
         if(node->key==temp->key){
         temp=temp->next;c=c+1;}// if matches make counter as counter +1
         else{
              temp=temp->next;
            }
        }
     if(c){} // if non zero don't add the node
     else{
     tail->next=node;
     tail=node;
    }
}
}
void insert_update(int key,int data)
{ 
    createNode(key,data);
    if(head==NULL){head=tail=node;}
    Node *temp=head;Node *temp2=NULL;
    while(temp!=NULL)
    {
        if(node->key==temp->key){temp->data=node->data;break;}
        else if(node->key>temp->key)
        {
                if(temp->next==NULL)
                {
                    temp->next=node;
                    break;
                }else{
                    temp2=temp;temp=temp->next;
                }
        }
        else{
              node->next=temp;
              temp2->next=node;
              break;
        }

    }
}
int search(int key)
{ 
    Node *temp=head;
    while(temp!=NULL)
    {
        if(key==temp->key){return temp->data;}
        else{temp=temp->next;}
    }return -1;
}
int isKeyExists(int key)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        if(key==temp->key){return 1;}
        else{temp=temp->next;}
    }return 0;
}
int delete(int key)
{ //int data=-1;
    Node *temp=head;
    Node *temp2=NULL;
    while(temp!=NULL)
    {
        if(key==temp->key)
        {
         int data=temp->data;
         temp2->next=temp->next;return data; 
        }else{
            temp2=temp;
            temp=temp->next;
        }
    }return -1;
}
int length()
{
    int data=0;Node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        data+=1;// calculate no. of keys in dictionary
    }return data;
}