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
    new_node->next = *head;

    *head = new_node;

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

struct Node *head;

int main()
{
    head = NULL;
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);

    printList(&head);

    return 0;
}
#include <stdio.h>
