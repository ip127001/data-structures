#include <bits/stdc++.h>

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

bool isBinarySearchTree(struct Node *root, int min_value, int max_value)
{
    if (root == NULL)
        return true;
    if (root->data > min_value &&
        root->data < max_value &&
        isBinarySearchTree(root->left, min_value, root->data) &&
        isBinarySearchTree(root->right, root->data, max_value))
        return true;
    else
        return false;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 57);

    if (isBinarySearchTree(root, INT_MIN, INT_MAX))
    {
        printf("tree is bst \n");
    }

    return 0;
}
