#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertBetween(struct Node **head, int data, int n)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (n == 1)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return;
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
    insertBetween(&head, 4, 1);
    insertBetween(&head, 6, 2);
    insertBetween(&head, 8, 2);
    insertBetween(&head, 10, 3);

    printList(&head);

    return 0;
}