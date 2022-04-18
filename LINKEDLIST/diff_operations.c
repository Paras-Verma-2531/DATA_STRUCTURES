# include <stdio.h> 
#include<stdlib.h>
typedef struct Node
{
	int data;struct Node *next;
}Node;
Node *node,*temp;
void add(int data,Node **head);
void display(Node **head);
void makenode(int data);
void reverse(Node **head);
void LastNodeAtFront(Node **head);
void firstElementAtLast(Node **head);
int length(Node **head);
void bringGivenNodeAtFront(int pos,Node **head);
int main() {
	Node *head=NULL;
	add(1,&head);
	add(2,&head);
	add(3,&head);
	add(4,&head);
	add(5,&head);
	display(&head);
	printf("  *******    \n");
	reverse(&head);
	display(&head);
	// printf("  last Node at Front....\n");
	// LastNodeAtFront(&head);
	// display(&head);
	// printf(" front Node at Last....\n");
	// firstElementAtLast(&head);
	// display(&head);
	//printf("%d\n",length(&head));
	// pos 3 Node at Front:
	printf("   pos 3 at Front : \n");
	bringGivenNodeAtFront(3,&head);
	display(&head);
 return 0 ;
}
void add(int data,Node **head)
{
   makenode(data);
   if(*head==NULL){*head=temp=node;}
   else{
	   temp->next=node;
	   temp=node;
   }
}
void makenode(int data)
{
	node=(Node *)malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
}
void reverse(Node **head)
{
	if(*head==NULL){printf("list is empty\n");}
	else if((*head)->next==NULL){return;}
	else{
		Node *current,*nextnode,*prev=NULL;
		current=nextnode=*head;
		while(current!=NULL)
		{
			nextnode=current->next;
			current->next=prev;
			prev=current;
			current=nextnode;
		}*head=prev;
	}
}
void display(Node **head)
{
	if(*head==NULL){printf("list is empty\n");}
	else{
		temp=*head;
		while (temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		
	}
}
void LastNodeAtFront(Node **head)
{
	if((*head)==NULL){printf("list is empty\n");}
	else if((*head)->next==NULL){return;}
	else{
		Node *temp1=NULL;
		temp=*head;
		while(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}temp1->next=NULL;
		temp->next=*head;
		*head=temp;
	}
}
void firstElementAtLast(Node **head)
{
	if((*head)==NULL){printf("list is empty\n");}
	else if((*head)->next==NULL){return;}
	else{
		Node *temp1=NULL;
		temp1=temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}temp->next=temp1;
		*head=(*head)->next;
		temp1->next=NULL;
	}
}
int length(Node **head)
{
	temp=*head;
	int c=0;
	if(temp!=NULL)
	{
		while(temp!=NULL)
		{
			c+=1;
			temp=temp->next;
		}
	}return c;
}
void bringGivenNodeAtFront(int pos,Node **head)
{
    if(pos<1||pos>length(head)){printf("invalid position!!\n");}
	else if(pos==1){return;}
	else if(pos==length(head)){LastNodeAtFront(head);}
	int i=1;temp=*head;
	Node *temp1=NULL;
	while(i<pos)
	{
		temp1=temp;
		temp=temp->next;
        i++;
	}temp1->next=temp->next;
	temp->next=*head;
	*head=temp;
}