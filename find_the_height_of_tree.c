#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

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

int findHeight(struct Node *root)
{
    int leftHeight, rightHeight;
    if (root == NULL)
    {
        return -1;
    }
    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);

    printf("height of tree: %d ", findHeight(root));
    return 0;
}