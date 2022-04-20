#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *next;
    int data;
} Node;
Node *node, *head, *current, *nextnode, *temp, *tail, *prev;
void makenode(int data);
void display();
void reverse();
void add(int data);
int main()
{
    add(1);
    add(2);
    add(3);
    add(4);
    reverse();
    display();
    return 0;
}
void makenode(int data)
{
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
}
void add(int data)
{
    makenode(data);
    if (head == NULL)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
    tail->next = head;
}
void reverse()
{
    if (head == NULL)
    {
        printf("list is empty\n");
    }
    else if (head->next == head)
    {
        display();
    }
    else
    {
        current = head;
        nextnode = current->next;
        while (current != tail)
        {
            prev = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prev;
        }
        nextnode->next = tail;
        head = tail;
        tail = nextnode;
    }
}
void display()
{
        if (head == NULL)
        {
            printf("list is empty\n");
        }
        else
        {
            temp = head;
            while (temp->next != head) // since the last node also contains the address of head therefore we will  exit when temp == head
            {
                printf("%d\n", temp->data);
                temp = temp->next;
            }
            printf("%d\n", temp->data);
        }
}