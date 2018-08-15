#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;

    new_node->data = data;
    new_node->next = NULL;

    if (temp == NULL)
    {
        *head = new_node;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void reverse(struct Node *n)
{
    if (n == NULL)
        return;
    printf("%d ", n->data);
    reverse(n->next);
}

void recursion(struct Node *n)
{
    if (n == NULL)
        return;
    recursion(n->next);
    printf("%d ", n->data);
}

int main()
{
    struct Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    reverse(head);
    printf("\n");
    recursion(head);

    return 0;
}