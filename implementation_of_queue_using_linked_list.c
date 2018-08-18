#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;

int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enQueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    if (isEmpty())
    {
        newNode->next = NULL;
        head = newNode;
        front = rear = 0;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->next = NULL;
    temp->next = newNode;
    rear = rear + 1;

    return;
}

void deQueue()
{
    if (isEmpty())
        return;
    struct Node *temp = head;
    head = temp->next;
    front = front + 1;

    free(temp);

    return;
}

void printList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main()
{
    head = NULL;
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    printList();

    deQueue();
    printList();

    return 0;
}
