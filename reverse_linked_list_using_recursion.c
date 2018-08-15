#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insert(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node *temp = head;
    if (head == NULL)
    {
        new_node->next = temp;
        head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    new_node->next = NULL;
    temp->next = new_node;

    return;
}

void reverseRecursion(struct Node *p)
{
    if (p->next == NULL)
    {
        head = p;
        return;
    }
    reverseRecursion(p->next);
    struct Node *q = p->next;
    q->next = p;
    p->next = NULL;
}

void printList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;

    insert(2);
    insert(4);
    insert(6);
    insert(8);
    insert(10);

    printList(head);

    reverseRecursion(head);

    printList(head);
    return 0;
}