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
    new_node->data = data;

    struct Node *temp = *head;
    if (*head == NULL)
    {
        new_node->next = temp;
        *head = new_node;
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

void reverse(struct Node **head)
{
    struct Node *temp, *current, *prev;
    temp = *head;
    prev = NULL;
    while (temp != NULL)
    {
        current = temp->next;
        temp->next = prev;
        prev = temp;

        temp = current;
    }
    *head = prev;
}

void printList(struct Node **head)
{
    struct Node *temp = *head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 10);

    printList(&head);

    reverse(&head);

    printList(&head);
    return 0;
}