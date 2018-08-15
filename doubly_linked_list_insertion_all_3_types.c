#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node *constructNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void insertAtHead(int n)
{
    struct Node *newNode = constructNode(n);
    struct Node *current = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    current->prev = newNode;
    head = newNode;
}

void insertAtEnd(int n)
{
    struct Node *newNode = constructNode(n);
    struct Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void reversePrint(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }
}

int main()
{
    head = NULL;

    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtEnd(40);

    printList(head);
    reversePrint(head);

    return 0;
}