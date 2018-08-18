#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->data = data;

    return newNode;
}

struct Node *insert(struct Node *head, int data)
{
    if (head == NULL)
    {
        head = createNode(data);
    }
    else if (head->data > data)
    {
        head->left = insert(head->left, data);
    }
    else
    {
        head->right = insert(head->right, data);
    }
    return head;
}

bool search(struct Node *head, int data)
{
    if (head == NULL)
    {
        return false;
    }
    else if (head->data == data)
    {
        return true;
    }
    else if (head->data > data)
    {
        return search(head->left, data);
    }
    else
    {
        return search(head->right, data);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);

    printf("%d \n", root->left->left->data);
    if (search(root, 25))
    {
        printf("element found");
    }
    else
    {
        printf("element not found");
    }

    return 0;
}