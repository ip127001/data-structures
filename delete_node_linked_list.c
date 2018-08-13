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

void delete (struct Node **head, int n)
{
    struct Node *temp = *head;

    if (n == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }

    struct Node *temp1 = temp->next;

    if (temp1->next == NULL)
    {
        temp->next = NULL;
        free(temp1);
        return;
    }

    temp->next = temp1->next;
    free(temp1);
}

void printList(struct Node **head)
{
    struct Node *temp = *head;

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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

    delete (&head, 3);
    delete (&head, 2);

    printList(&head);
    return 0;
}