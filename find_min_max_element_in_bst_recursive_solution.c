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
    if (root->left == NULL)
    {
        return root->data;
    }
    return minNode(current->left);
}

int maxNode(struct Node *root)
{
    struct Node *current = root;
    if (root == NULL)
    {
        printf("tree is empty, no node to tranverse");
        return -1;
    }
    if (root->right == NULL)
    {
        return root->data;
    }
    return maxNode(current->right);
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);

    printf("min node: %d ", minNode(root));
    printf("max node: %d ", maxNode(root));

    return 0;
}