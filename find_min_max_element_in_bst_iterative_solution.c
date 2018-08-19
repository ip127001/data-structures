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

int minNode(struct Node *root)
{
    struct Node *current = root;
    if (root == NULL)
    {
        printf("tree is empty, no node to tranverse");
        return -1;
    }
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

int maxNode(struct Node *root)
{
    struct Node *current = root;
    if (root == NULL)
    {
        printf("tree is empty, no node to tranverse");
        return -1;
    }
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);

    printf("min node: %d ", minNode(root));
    printf("max node: %d ", maxNode(root));

    return 0;
}